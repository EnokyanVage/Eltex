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
                perror("Error");
                exit(1); 
            break;
        case 0:
            if (execl("./test","",NULL) < 0) 
            {    
                perror("Error\n");
                exit(1);
            }
            break;
            default:
		        waitpid(PID,NULL,0);
    }
}