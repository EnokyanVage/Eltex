#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MY_PORT 7777

int main()
{
    int fd;
    int my_connect;
    struct sockaddr_in my_client;

    char message[] = "Hello!\n";
    char buffer[sizeof(message)];


    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    my_client.sin_family = AF_INET;
    my_client.sin_port = htons(MY_PORT); // 7777
    my_client.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    my_connect = connect(fd, (struct sockaddr *)&my_client, sizeof(my_client));
    if(my_connect < 0)
    {
        perror("connect");
        return -1;
    }

    send(fd, message, sizeof(message), 0);
    recv(fd, buffer, sizeof(message), 0);
    
    printf("byffer = %s",buffer);

    close(fd);

    return 0;
}