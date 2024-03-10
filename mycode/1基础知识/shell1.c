#include "apue.h"
#include <sys/wait.h>

/**
 * 从标准输入读命令并执行
 * 
 * fgets一次读一行，当键入文件结束符（ctrl+D）作为行的一个字符时，
 * fgets返回一个null指针，循环停止，进程终止
 * 
 * fork创建新进程，新进程时调用进程的副本，也是子进程
 * fork进程对父进程返回新的子进程的ID（非负整），对子进程返回0
 * 
 * 子进程中，调用execlp来执行从标准输入读入的命令，用新的程序替换
 * 子进程原先执行的程序
 * 
 * fork和其后的exec的两者组合就是某些OS所称的孵化（spawn）一个新进程
 * 
 * 子进程调用execlp执行新程序文件，父进程希望等待子进程终止，这通过waitpid实现
 * 其参数指定要等待的进程（即pid参数是子进程id）
 * waitpid函数返回子进程的终止状态（status变量），可通过此值准确判定子进程是如何终止的
 * 
 * 本程序的主要限制：
 *  不能向所执行的命令传递参数
 * 但仍可用于说明UNIX系统的进程控制功能
 */
int
main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    printf("%% ");
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) -  1] == '\n')
            buf[strlen(buf) - 1] = 0; // 用null替代换行符，满足execlp函数的要求
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) { // 子进程
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        // 父进程
        if ((pid = waitpid(pid, &status, 0)) < 0)
            err_sys("waitpid error");
        printf("%% ");
    }

    exit(0);
}