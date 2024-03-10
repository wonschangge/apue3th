#include "apue.h"
#include <sys/wait.h>

/**
 * 从标准输入读指令并执行 
 */
static void sig_int(int); // 我们的信号处理函数（signal-catching func）

int
main(void)
{
    char    buf[MAXLINE];
    pid_t   pid;
    int     status;

    if (signal(SIGINT, sig_int) == SIG_ERR)
        err_sys("signal error");

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

void
sig_int(int signo)
{
    printf("interrupt\n%% ");
}