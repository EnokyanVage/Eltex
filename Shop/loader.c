#include "loader.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t loader_store = PTHREAD_MUTEX_INITIALIZER;
extern int store[SHOP];
extern int step;

void* loader(void *arg)
{

    while(step < 3)
    {
        for(int i = 0; i < SHOP; i++)
        {
            pthread_mutex_lock(&loader_store);
            store[i] += 200;
            printf("---------------------------------------------------\n");
            printf("Погрузчик загрузил в магазин 200 товаро \n");
            printf("В магазине %d сейчас %d товаров \n",i,store[i]);
            printf("---------------------------------------------------\n");
            pthread_mutex_unlock(&loader_store);
            sleep(2);
        }
    }
}