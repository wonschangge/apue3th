#include "apue.h"

/**
 * 打印用户ID和组ID
 * 
 * unistd.h 提供 getuid 和 getpid 函数
 */
int
main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}