#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    int fd[2];
    char message[6];
    if(pipe(fd) == -1)
    {
        return 1;
    }

    pid_t PID;
    PID = fork();

    if(PID == -1)
    {
        perror("Error");
        exit(-1);
    }
    if(PID > 0)
    {
        close(fd[0]);
        write(fd[1],"Hello",6);
        close(fd[1]);
        exit(0);
    }
    else 
    {
        close(fd[1]);
        //dup2(fd[0],0);
        read(fd[0],message,6);
        printf("%s\n",message);
        close(fd[0]);
        exit(0);
    }
}