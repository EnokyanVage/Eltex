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
    my_client.sin_addr.s_addr = htonl(INADDR_ANY);

    int flag = 1;
    const int *val = &flag;

    int my_setsock = setsockopt(fd, IPPROTO_IP, IP_HDRINCL, &flag, sizeof(flag));
    if(my_setsock == -1)
    {
        perror("setsock");
        exit(EXIT_FAILURE);
    }

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

    char *packet = malloc(MY_SIZE_PACKET * sizeof(char));
    char *buffer = malloc((MY_SIZE_PACKET - llen) * sizeof(char));

    struct iphdr *Header;
    Header = (struct iphdr *)packet;

	struct udphdr *udpHeader;
    udpHeader = (struct udphdr *) (packet + sizeof(struct iphdr));

    int my_send_recv;


    fgets(buffer, MY_SIZE_PACKET - llen, stdin);
    memmove(packet + 8, buffer, strlen(buffer) - 1);

    Header->ihl = 5;
    Header->version = 4;
    Header->tos = 0;
    Header->id=htonl(23781);
    Header->frag_off = 0;
    Header->ttl = 255;
    Header->protocol = IPPROTO_UDP;
    Header->saddr = INADDR_ANY;
    Header->daddr = my_client.sin_addr.s_addr;

	udpHeader->source = htons(MY_PORT);
	udpHeader->dest = htons(SERVER_PORT);
	udpHeader->check = 0;
	udpHeader->len = htons(strlen(buffer) - 1 + sizeof(struct udphdr));

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

        if(ntohs(udpHeader->dest) == MY_PORT)
        {
            printf("Packet = %d bytes\n", my_send_recv);
            printf("Message: %s\n\n", packet + sizeof(struct iphdr) + sizeof(struct udphdr));
            
            break;
        }
    }
    free(buffer);
    free(packet);
}
