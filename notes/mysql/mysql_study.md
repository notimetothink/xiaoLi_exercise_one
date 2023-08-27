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