#ifndef THREAD_CLIENT_H
#define THREAD_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define MY_BUFFER_SIZE 1024
#define MY_CLIENT 100

void *Thread_client(void *);

#endif // THREAD_CLIENT_H