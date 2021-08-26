#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(void)
{
    int fd;
    int i = 1;
    int my_setsockopt, my_sendto;
    char buffer[] = "Hello!\n";
    struct sockaddr_in server;

    int len = sizeof(server);

    server.sin_family = AF_INET;
    server.sin_port = htons(7777);
    server.sin_addr.s_addr = inet_addr("255.255.255.255");

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    my_setsockopt = setsockopt(fd,SOL_SOCKET, SO_BROADCAST, &i, sizeof(i));

    my_sendto = sendto(fd,buffer,sizeof(buffer), 0, (struct sockaddr *)&server, len);
    if(my_sendto < 0)
    {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    printf("Message: %s",buffer);

    return 0;
}


