#include "apue.h"

/**
 * 打印进程ID
 * 
 * unistd.h 提供 getpid 函数
 * getpid 返回一个 pid_t 数据类型，但不知道其大小，
 * 仅知道UNIX标准会保证它能保存在一个长整型中
 */
int
main(void)
{
    printf("hello world from process ID %ld\n", (long)getpid());
    exit(0);
}