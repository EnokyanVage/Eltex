#include "customer.h"
#include "random.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

pthread_mutex_t customer_store = PTHREAD_MUTEX_INITIALIZER;
int step = 0;
pthread_mutex_t step_st = PTHREAD_MUTEX_INITIALIZER;

extern int store[SHOP];

void* customer(void *arg)
{
    int cust = RANDOM(1000,1010);
    int buyer = *((int *) arg);
    while(cust > 0)
    {
        for(int shoping = 0; shoping < SHOP; shoping++)
        {
            pthread_mutex_lock(&customer_store);
            cust-= store[shoping];
            printf("---------------------------------------------------\n");
            printf("Посетил в магазин %d, Потребность %d, Клиент %d\n", shoping, cust, buyer);
            printf("---------------------------------------------------\n");
            store[shoping] = 0;
            pthread_mutex_unlock(&customer_store);
            sleep(1);
        }
    }
    pthread_mutex_lock(&step_st);
    step++;
    pthread_mutex_unlock(&step_st);
}