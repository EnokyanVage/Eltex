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
    int my_sendto;

    char buffer[] = "Hello!\n";

    struct sockaddr_in client;
    int len = sizeof(client);      


    client.sin_family = AF_INET;
    client.sin_port = htons(7777);
    client.sin_addr.s_addr = inet_addr("224.0.0.1");

    fd = socket(AF_INET, SOCK_DGRAM, 0);

    my_sendto = sendto(fd,buffer,sizeof(buffer), 0, (struct sockaddr *)&client, len);
    if(my_sendto< 0)
    {
        perror("sendto");
        return -1;
    }
    
    printf("Message: %s",buffer);

    return 0;
}

