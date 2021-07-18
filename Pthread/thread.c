#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int a = 0;

void *func(void *args)
{
    int i, tmp;

    for(i = 0; i < 1000; i++)
    {
        tmp = a;
        tmp ++;
        a = tmp;
    }
}
int main(void)
{
    pthread_t tid[1000];
    int i;

    for(i = 1; i <= 1000; i++)
    {
        pthread_create(&tid[i-1],NULL,func,NULL);
    }

    for(i = 1; i <= 1000; i++)
    {
        pthread_join(tid[i-1],NULL);
    }

    printf("a = %d\n", a);

    return 0;

}