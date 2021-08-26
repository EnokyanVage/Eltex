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
    int my_bind, my_recvfrom;
    char buffer[BUFFER_SIZE] = {0};
    struct sockaddr_in client, server;

    int len = sizeof(server);

    client.sin_family = AF_INET;
    client.sin_port = htons(7777);
    client.sin_addr.s_addr = inet_addr("255.255.255.255");

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    my_bind = bind(fd,(struct sockaddr *)&client, sizeof(client));
    if(my_bind < 0)
    {
        perror("bind");
        return -1;
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