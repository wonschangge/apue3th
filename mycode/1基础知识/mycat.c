#include "apue.h"

#define BUFFSIZE    4096

/**
 * 将标准输入复制到标准输出
 * 
 * 使用方式: ./a.out < infile > outfile
 * 
 * unitstd.h 提供常量 STDIN_FILENO 和 STDOUT_FILENO
 * read 函数返回读取的字节数，此值用于要写的字节数，
 * 当到达输入文件的尾端时，read返回0，程序停止。
 * 如果发生读错误，read返回-1。
 */
int
main(void)
{
    int     n;  // 表示fd
    char    buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");

    if (n < 0)
        err_sys("read error");

    exit(0);    
}