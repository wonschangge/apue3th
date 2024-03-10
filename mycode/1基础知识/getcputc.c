#include "apue.h"

/**
 * 用标准I/O将标准输入复制到标准输出
 * 
 * getc 一次读取一个字符，然后 putc 将此字符写入到标准输出
 * 
 * stdio.h 中定义了标准I/O常量 stdin 和 stdout
 */
int
main(void)
{
    int         c;

    while ((c = getc(stdin)) != EOF)
        if (putc(c, stdout) == EOF)
            err_sys("output error");
    
    if (ferror(stdin))
        err_sys("input error");
    
    exit(0);
}