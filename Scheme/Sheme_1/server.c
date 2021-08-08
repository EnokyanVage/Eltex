#include "thread_client.h"

int main(void)
{
    struct sockaddr_in my_server;
    int fd;
    int server_socket;
    int my_socket;
    int my_bind;
    char buffer[MY_BUFFER_SIZE];

    fd = socket(AF_INET,SOCK_STREAM,0);

    if(fd == -1)
    {
        perror("fd\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Good!\n");
    }

    my_server.sin_family = AF_INET;
    my_server.sin_port = htons(7777);
    my_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    my_bind = bind(fd,(struct sockaddr *)&my_server, sizeof(my_server));
    if(my_bind < 0)
    {
        perror("bind");
        return -1;
    }
    else
    {
        printf("Bind Good!\n");
    }

    listen(fd,5);

    pthread_t pthread_id[MY_CLIENT] = {0};
    int fd_socket[MY_CLIENT];

    for(int i = 0; i < MY_CLIENT; i ++)
    {
        fd_socket[i] =  accept(fd, NULL, NULL);
        if(fd_socket[i] == -1)
        {
            perror("fd_socket");
            exit(EXIT_FAILURE);
        }

        void *args = (void *)&fd_socket[i];

        if(pthread_create(&pthread_id[i], NULL, Thread_client, args))
        {
            perror("Error create");
            exit(EXIT_FAILURE);
        } 

    }


    close(fd);

    return 0;
}