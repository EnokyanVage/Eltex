#include "customer.h"
#include "loader.h"

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int store[SHOP] = {0};

int main(void)
{
    pthread_t customer_a[BUYER];
    pthread_t loaders;
    int i,j;
    

    pthread_create(&loaders, NULL, loader, NULL);

    for ( i = 0; i < BUYER; i++) 
    {
        pthread_create(&customer_a[i], NULL, customer, &i);
    }
    pthread_join(loaders, NULL);

    for (j = 0; j < BUYER; j++) 
    {
        pthread_join(customer_a[j], NULL);
    }
    exit(BUYER);
}