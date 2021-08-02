#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MY_PORT 5555

int main()
{
    int fd;
    int my_connect;
    int my_socket;
    struct sockaddr_in my_client;

    char message[] = "Hello!\n";
    char buffer[sizeof(message)];


    fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    my_client.sin_family = AF_INET;
    my_client.sin_port = htons(MY_PORT); // 5555
    my_client.sin_addr.s_addr = htonl(INADDR_LOOPBACK);


    if(sendto(fd, message, sizeof(message), 0,(struct sockaddr *)&my_client, sizeof(my_client)) < 0)
    {
        perror("sendto!\n");
        return -2;
    }
    close(fd);

    return 0;
}
