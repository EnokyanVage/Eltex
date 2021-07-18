#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    pid_t PID;
    PID = fork(); 
    switch (PID)
    {
        case -1:
            perror("fork");
            exit(1);
            break;
        case 0:
            printf("My PID - %d \n", getpid());
            printf("My parent PID - %d \n", getppid());
            break;
        default:
            printf("My PID - %d \n", getpid());
            printf("PID my descendant - %d \n", getppid());
            break;
    }
    exit(0);
}
