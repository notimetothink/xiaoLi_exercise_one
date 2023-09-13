# MySQL
## 存储引擎
查看数据库支持的存储引擎
```sql
show engines 
```
## MySQL连接
在通过TCP/IP连接到MySQL实例时，会先检查权限视图。
位于mysql库user表
# InnoDB
查看InnoDB版本
```sql
SHOW VARIABLES LIKE 'innodb_version';
```
查看InnoDB
```sql
SHOW ENGINE INNODB STATUS;
```
## 后台线程
### Master Thread
### IO Thread
查看innodb_read_io_threads、innodb_write_io_threads的参数配置
```sql
SHOW VARIABLES LIKE 'innodb_read_io_threads';
SHOW VARIABLES LIKE 'innodb_write_io_threads';
```
使用```SHOW ENGINE INNODB STATUS```命令观察IO thread
```
--------
FILE I/O
--------
I/O thread 0 state: wait Windows aio ((null))
I/O thread 1 state: wait Windows aio (insert buffer thread)
I/O thread 2 state: wait Windows aio (read thread)
I/O thread 3 state: wait Windows aio (read thread)
I/O thread 4 state: wait Windows aio (read thread)
I/O thread 5 state: wait Windows aio (read thread)
I/O thread 6 state: wait Windows aio (write thread)
I/O thread 7 state: wait Windows aio (write thread)
I/O thread 8 state: wait Windows aio (write thread)
```
### Purge Thread
查看innodb_purge_threads的参数配置
```sql
SHOW VARIABLES LIKE 'innodb_purge_threads';
```
### Page Cleaner Thread

## 缓冲池
配置innodb_buffer_pool_size设置缓冲池大小
```sql
SHOW VARIABLES LIKE 'innodb_buffer_pool_size';
```
配置innodb_buffer_pool_instances设置缓冲池数量
```sql
SHOW VARIABLES LIKE 'innodb_buffer_pool_instances';
```
### LRU(Latest Recent Used)

#### 原理
缓冲池通过LRU(最近最少使用)算法管理，缓冲池中页大小默认16KB，InnoDB对LRU做了优化：
- LRU列表加入了midpoint位置，新读到的页放在midpoint位置而非列表首部
- ```innodb_old_blocks_pct```参数控制midpoint位置，查询出的数值表示新读到的页插入到LRU列表尾部百分值的位置

```sql
SHOW VARIABLES LIKE 'innodb_old_blocks_pct';
```
- midpoint后成为old列表，前为new列表，new列表中为最活跃的热点数据
- 采用midpoint insertion strategy的原因是防止一些操作读取大量页(而且这操作只需要一次)刷新真正的热点数据
- ```innodb_old_blocks_time```参数用于表示页读取到mid位置后等待多久会被加入到LRU列表热端
```sql
SHOW VARIABLES LIKE 'innodb_old_blocks_time';
```
- 修改
```sql
SET GLOBAL innodb_old_blocks_time = 1000;
SET GLOBAL innodb_old_blocks_pct = 20;
```
- LRU列表用来管理已经读取的页
- 数据库启动时，LRU列表是空的，此时页都在Free列表
- 当需要从缓存池分页时，先在Free列表查找有无可用空闲页，有在Free列表删除，插入LRU列表，否则，根据LRU，淘汰队尾，插入新页

#### 使用```SHOW ENGINE INNODB STATUS```命令观察
```
Buffer pool size   8191
Free buffers       7018
Database pages     1157
Old database pages 407
Modified db pages  0
Pending reads      0
Pending writes: LRU 0, flush list 0, single page 0
Pages made young 140, not young 64
0.00 youngs/s, 0.00 non-youngs/s
Pages read 1014, created 146, written 238
0.00 reads/s, 0.00 creates/s, 0.00 writes/s
Buffer pool hit rate 1000/1000
Pages read ahead 0.00/s, evicted without access 0.00/s, Random read ahead 0.00/s
LRU len: 1157, unzip_LRU len: 0
I/O sum[0]:cur[0], unzip sum[0]:cur[0]
```
- 当页从LRU列表old部分加到new部分，成为page made young；反之为page not made young
- Buffer pool size缓冲池页数，Buffer pool size*16K
- Free buffers，Free列表里页的数量
- Database pages，LRU列表页个数
- Free buffers+Database pages不一定=Buffer pool size，缓冲池的页还会分给自适应哈希索引、Lock信息、Insert Buffer等页
- `Buffer pool hit rate`，表示缓冲池命中率，该值通常不应小于95%

#### INNODB_BUFFER_PAGE_LRU
- 可以通过INNODB_BUFFER_PAGE_LRU表观察每个LRU列表每个页的具体信息

#### 压缩页
- 将16KB的页压缩为1、2、4、8KB
- unzip_LRU列表管理压缩页
- 使用```SHOW ENGINE INNODB STATUS```命令观察
```
LRU len: 1157, unzip_LRU len: 0
I/O sum[0]:cur[0], unzip sum[0]:cur[0]
```
- INNODB_BUFFER_PAGE_LRU可查看unzip_LRU列表里的页，通过COMPRESSED_SIZE字段判断
```sql
SELECT * FROM INNODB_BUFFER_PAGE_LRU WHERE COMPRESSED_SIZE <> 0
```
<> 0 表示不等于0
##### unzip_LRU列表内存分配
- unzip_LRU列表对不同大小压缩页进行分别管理
- 通过伙伴算法进行内存分配，举例4KB
 1. 检查4KB列表有无空闲页，有直接用
 2. 没有去检查8KB列表，有分成两个4KB存入4KB列表
 3. 没有8KB去LRU列表申请一个16，分成1个8两个4

#### Flush列表

- LRU列表里的页被修改后，称为脏页，即缓冲池中的页和磁盘上的页数据产生了不一致
- Flush列表为脏页列表
- 脏页既存在于LRU列表中，也存在与Flush列表中
- `SHOW ENGINE INNODB STATUS`命令里`Modified db pages xx`显示脏页数量
- 可以通过`INNODB_BUFFER_PAGE_LRU`查看脏页信息，使用`OLDEST_MODIFICATION`筛选
```sql
SELECT * FROM INNODB_BUFFER_PAGE_LRU WHERE OLDEST_MODIFICATION > 0
```

## 重做日志缓冲(redo log buffer)
- InnoDB首先将重做日志信息放到缓冲区，按一定频率刷新到重做日志文件
- 缓冲区大小由参数`innodb_log_buffer_size`配置
```sql
SHOW VARIABLES LIKE 'innodb_log_buffer_size';
```
- 以下情况重做日志缓冲刷新到重做日志文件
  1. Master Thread每秒将重做日志缓冲刷新到重做日志文件
  2. 每个事务提交时
  3. 重做日志缓冲池剩余不足50%

## 额外的内存池
- 对一些数据结构本身的内存进行分配时，需要从额外的内存池中进行申请，当该区域内存不够时，会从缓冲池进行申请
- 申请了很大的缓冲池，额外的内存池也要提高

## Checkpoint技术
- Checkpoint技术用于将脏页刷新到磁盘
- 为防止数据丢失，当前事务型数据库采用Write Ahead Log 策略，即当事务提交时，先重做日志，再修改页，数据丢失时，通过重做日志恢复数据
- Checkpoint解决以下问题
  1. 缩短数据库恢复时间：数据库宕机时，只需对Checkpoint后的重做日志进行恢复，因为Checkpoint前的页都刷新回了磁盘
  2. 缓冲池不够用，LRU算法溢出最近最少使用页，此页为脏页强制执行Checkpoint，将脏页刷新到磁盘
  3. 重用日志不可用时(因为重用日志循环使用,不是无限增大)，刷新脏页
- LSN(Log Sequence Number)来标记版本；
  通过`SHOW ENGINE INNODB STATUS`命令查看
  ```
  LOG
  ---
  Log sequence number          32260471
  Log buffer assigned up to    32260471
  Log buffer completed up to   32260471
  Log written up to            32260471
  Log flushed up to            32260471
  Added dirty pages up to      32260471
  Pages flushed up to          32260471
  Last checkpoint at           32260471 // checkpoint
  ```
- InnoDB中有两种Checkpoint，Sharp Checkpoint和Fuzzy Checkpoint
- Sharp Checkpoint发生在数据库关闭时将所有脏页刷新回磁盘，参数innodb_fast_shutdown = 1
- 数据库运行时使用Fuzzy Checkpoint，包括Master Thread Checkpoint、FLUSH_LRU_LIST Checkpoint、 Async/Sync Flush Checkpoint、 Dirty Page too much Checkpoint

### Master Thread Checkpoint
- Master Thread内发生，异步，以每秒或每10秒刷新一定比例

### FLUSH_LRU_LIST Checkpoint
- Page Cleaner线程中，当LRU列表尾部页移除时Checkpoint
- InnoDB保证有一定数量空闲页在LRU内
- innodb_lru_scan_depth参数控制LRU可用页数量
  
### Async/Sync Flush Checkpoint
- 重做日志不可用情况
  ![现代计算机系统硬件框图](images/checkpoint.jpg)

### Dirty Page too much Checkpoint
- 脏页数量太多进行Checkpoint
- `inoodb_max_dirty_pages_pct`参数控制,当缓冲池脏页数量占百分之`inoodb_max_dirty_pages_pct`时，刷新一部分脏页

## Master Thread
### 1.0.x版本前
#### loop循环(主循环)
- 每秒操作
  1. (总是)日志缓冲刷新到磁盘，即使事务还没提交，这是大事务提交时间短的原因
  2. (可能)合并插入缓冲，前一秒IO小于5次的话
  3. (可能)至多刷新100个脏页到磁盘，超过`inoodb_max_dirty_pages_pct`时
  4. (可能)如果当前没有用户活动，则切换到background loop
- 每10秒操作
  1. (可能)刷新100个脏页到磁盘：判断过去10秒内IO操作是否小于200次
  2. 合并至多5个插入缓冲