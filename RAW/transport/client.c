#include <stdio.h>
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netinet/udp.h>
#include <netinet/ip.h>
#include <arpa/inet.h> 
#include <stdlib.h> 
#include <unistd.h>

#define MY_PORT 7888
#define SERVER_PORT 7777
#define MY_SIZE_PACKET 256
void client(struct sockaddr_in my_client, int fd);

int main()
{
    int fd;
    int my_connect;
    struct sockaddr_in my_client;

    fd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    if(fd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    my_client.sin_family = AF_INET;
    my_client.sin_port = htons(SERVER_PORT);
    my_client.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    while(1)
    {
        client(my_client,fd);
    }
    close(fd);

    return 0;
}

void client(struct sockaddr_in my_client, int fd)
{
    socklen_t llen = sizeof(struct sockaddr_in);
	struct udphdr *Header;
    int my_send_recv;

    char *buffer = malloc((MY_SIZE_PACKET - llen) * sizeof(char));
	char *packet = malloc(MY_SIZE_PACKET - sizeof(char));

    fgets(buffer, MY_SIZE_PACKET - llen, stdin);
    memmove(packet + 8, buffer, strlen(buffer) - 1);

	Header = (struct udphdr *)packet;
	Header->source = htons(MY_PORT);
	Header->dest = htons(SERVER_PORT);
	Header->check = 0;
	Header->len = htons(strlen(buffer) - 1 + sizeof(struct udphdr));

    my_send_recv = sendto(fd, packet, MY_SIZE_PACKET, 0, (struct sockaddr *)&my_client, llen);
    if(my_send_recv == -1)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    while(1)
    {
        my_send_recv = recvfrom(fd, packet, MY_SIZE_PACKET, 0, (struct sockaddr *)&my_client, &llen);
        if(my_send_recv == -1)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }
        
        struct iphdr *ipheader = (struct iphdr *)packet;
        Header = (struct udphdr *) (packet + sizeof(struct iphdr));

        if(ntohs(Header->dest) == MY_PORT)
        {
            printf("Packet = %d bytes\n", my_send_recv);
            printf("Message: %s\n\n", packet + sizeof(struct iphdr) + sizeof(struct udphdr));
            
            break;
        }
    }
    free(buffer);
    free(packet);
}