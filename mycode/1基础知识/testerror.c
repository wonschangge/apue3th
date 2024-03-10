#include "apue.h"
#include <errno.h>

/**
 * 使用strerror和perror的示例
 * 
 * 将程序名(argv[0])作为参数传给perror，这是一个标准的UNIX惯例：
 * 在程序作为管道的一部分执行时，如：
 * prog1 < inputfile | prog2 | prog3 > outputfile，
 * 就能分清3个程序中的哪个产生了一条特定的出错消息
*/
int
main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}