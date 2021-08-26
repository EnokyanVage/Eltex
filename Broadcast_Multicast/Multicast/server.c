#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 256

int main(void)
{
    int fd;
    int my_recvfrom, my_bind;

    char buffer[BUFFER_SIZE] = {0};

    struct sockaddr_in server;
    struct ip_mreq mreq;

    int len = sizeof(server);

    server.sin_family = AF_INET;
    server.sin_port = htons(7777);
    server.sin_addr.s_addr = htonl(INADDR_ANY);

    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd == -1)
    {
        perror("fd");
        exit(EXIT_FAILURE);
    }

    setsockopt(fd,IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

    my_bind = bind(fd, (struct sockaddr *)&server, sizeof(server));
    if(my_bind == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    my_recvfrom = recvfrom(fd,buffer,BUFFER_SIZE, 0, (struct sockaddr *)&server, &len);
    if(my_recvfrom < 0)
    {
        perror("recvfrom");
        return -1;
    }

    printf("Message: %s",buffer);

    return 0;
}
