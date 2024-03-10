#include "apue.h"
#include <dirent.h>

/**
 * 列出一个目录中的所有文件
 * 
 * dirent.h 提供 opendir, readdir 函数和 dirent 结构的定义
 * err_sys 说明遇到的错误，一般是 "Permisson denied" 或 "Not a directory"
 */
int
main(int argc, char *argv[])
{
    DIR             *dp;
    struct dirent   *dirp;

    if (argc != 2)
        err_quit("usage: ls directory_name");
    
    if ((dp = opendir(argv[1])) == NULL)
        err_sys("can't open %s", argv[1]);
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    
    closedir(dp);
    exit(0);
}