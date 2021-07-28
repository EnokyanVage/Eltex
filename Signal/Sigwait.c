#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{
    printf("signal %i\n", signum);
}

int main(void)
{
    sigset_t mask;
    struct sigaction action;

    sigemptyset(&mask);

    sigprocmask(SIG_SETMASK,&mask,0);
    action.sa_handler = handler;

    sigaction(SIGTERM,&action,0);

    while(1)
    {
        int sig;
        sigwait(&mask,&sig);
    }
}
// kill -15 PID