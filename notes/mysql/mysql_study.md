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
- 使用```SHOW ENGINE INNODB STATUS```命令观察
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
- Buffer pool size缓冲池页数
- 
