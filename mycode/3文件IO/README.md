文件I/O函数：
- 打开文件
- 读文件
- 写文件

UNIX中的大多数文件I/O只需5个函数：
- open
- read
- write
- lseek
- close

不带缓冲的I/O（unbuffered I/O），不带缓冲指每个read和write都调用内核中的一个系统调用，不带缓冲的I/O函数不是ISO C的组成部分，但它是POSIX.1和Single UNIX Specification的组成部分