#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t X,Y,Z;
    printf("Parent PID = %d\n", getpid());
    printf("Parent РPID = %d\n", getppid());
    for (int i = 0; i < 2; i++){
        X = fork();
        if (X == 0){
            printf("%i PID = %d\n",i, getpid());
            printf("%i PPID = %d\n",i,  getppid());
            if (i == 0) 
            {
                for (int j = 0; j < 2; j++){
                    Y = fork();
                    if (Y == 0){
                        printf("1.%i PID = %d\n",j, getpid());
                        printf("1.%i PPID = %d\n",j, getppid());
                        break;
                    }		
                }
                    
            }
            if (i == 1){
                Z = fork ();
                if (Z == 0){
                    printf("2.%i PID = %d\n",i, getpid());
                    printf("2.%i PPID = %d\n",i, getppid());
                }
            }
            break;
        }
    }
    wait(NULL);
    return 0;
}
