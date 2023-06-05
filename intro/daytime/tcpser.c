#include <util/unp.h>

#include <stdio.h>
#include <time.h>
#include <string.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int serverfd, clientfd;
    char buffer[MAX_LINE + 1];

    struct sockaddr_in serveraddr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
    };

    if (inet_pton(AF_INET, "0.0.0.0", &serveraddr.sin_addr) < 0)
    {
        ERROR(inet_pton)
    }

    if ((serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        ERROR(sockfd = socket)
    }

    if (bind(serverfd, SA(serveraddr), sizeof(serveraddr)) < 0)
    {
        ERROR(bind)
    }

    if (listen(serverfd, /*connections*/ 1) < 0)
    {
        ERROR(listen)
    }

    while (1)
    {
        struct sockaddr client_socket;
        int client_socket_length;
        if ( (clientfd = accept(serverfd, &client_socket, &client_socket_length)) < 0)
        {
            ERROR(clientfd = accept)
        }
        time_t t = time(NULL);
        char *time_str = ctime(&t);
        write(clientfd, time_str, strlen(time_str));
        close(clientfd);
    }
}