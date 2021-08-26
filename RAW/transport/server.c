#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 


#define MY_PORT 7777
#define MY_BUFFER_SIZE 256

int main(void)
{
    struct sockaddr_in my_server, my_client;
    int fd;
    int server_socket;
    int my_socket;
    int my_bind;

    fd = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
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
    my_server.sin_port = htons(MY_PORT);
    my_server.sin_addr.s_addr = htonl(INADDR_ANY);
    
    socklen_t llen = sizeof(struct sockaddr_in);

    my_bind = bind(fd,(struct sockaddr *)&my_server, llen);
    if(my_bind < 0)
    {
        perror("bind");
        return -1;
    }
    else
    {
        printf("Bind Good!\n");
    }

    while(1)
    {
		char buffer[MY_BUFFER_SIZE] = {0};
        memset(&my_client,0,sizeof(struct sockaddr_in));
        llen = sizeof(struct sockaddr_in);
        my_socket = recvfrom(fd,buffer,MY_BUFFER_SIZE,0, (struct sockaddr *)&my_client, &llen);
        
        if(my_socket <= 0)
        {
            break;
        }
		printf("Message = %d bytes: %s\n", my_socket, buffer);
		
        my_socket = sendto(fd,buffer,MY_BUFFER_SIZE,0,(struct sockaddr *)&my_client, llen);

        if(my_socket <= 0)
        {
            break;
        }

    }
    close(fd);
    
    return 0;
}

