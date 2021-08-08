#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MY_BUFFER_SIZE 1024

int main(void)
{

    int fd;
    int my_connect;
    struct sockaddr_in my_client;

    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    my_client.sin_family = AF_INET;
    my_client.sin_port = htons(7777); 
    my_client.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    my_connect = connect(fd, (struct sockaddr *)&my_client, sizeof(my_client));
    if(my_connect < 0)
    {
        perror("connect");
        return -1;
    }

    while(1)
    {
        char buffer[MY_BUFFER_SIZE] = {0};
        printf("Client: ");
		fgets(buffer, MY_BUFFER_SIZE, stdin);

        if((send(fd, buffer, strlen(buffer) - 1, 0)) == -1)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }

        if (strncmp(buffer, "Close", 3) == 0)
        break;

        int my_recv = recv(fd, buffer, MY_BUFFER_SIZE, 0);
        if(my_recv == -1)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

    }

    close(fd);

    return 0;
}