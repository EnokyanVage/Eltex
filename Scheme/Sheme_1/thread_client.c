#include "thread_client.h"

void *Thread_client(void *args)
{
    int *fd_socket = (int *)args;
    char buffer[MY_BUFFER_SIZE] = {0};

    while(1)
    {
        if((recv(*fd_socket, buffer, MY_BUFFER_SIZE, 0)) == -1)
        {
            perror("recv");
            exit(EXIT_FAILURE);  
        }

		if (strncmp(buffer, "Close", MY_BUFFER_SIZE) == 0) {
			printf("Close fd == %d\n", *fd_socket);
			close(*fd_socket);
			*fd_socket = -1;
			pthread_exit(0);
		}

        if((send(*fd_socket, buffer, MY_BUFFER_SIZE, 0)) == -1)
        {
            perror("send");
            exit(EXIT_FAILURE);
        }


        printf("%s\n", buffer);
    }
}