#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>         
#include <sys/socket.h>
#include <netinet/in.h>

#define MY_PORT 7777
#define MY_BUFFER_SIZE 1024

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
    my_server.sin_port = htons(MY_PORT); // 7777
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

    server_socket = accept(fd,NULL,NULL);
    if(server_socket < 0)
    {
        perror("accept");
        return -2;
    }

    while(1)
    {
        
        my_socket = recv(server_socket,buffer,MY_BUFFER_SIZE,0);
        
        if(my_socket <= 0)
        {
            break;
        }

        my_socket = send(server_socket,buffer,MY_BUFFER_SIZE,0);

        if(my_socket <= 0)
        {
            break;
        }

        printf("byffer = %s",buffer);

    }
    close(fd);
    
    return 0;
}

