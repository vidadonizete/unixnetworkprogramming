#include <util/unp.h>

#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int serverfd, n;
    char buffer[MAX_LINE + 1];

    struct sockaddr_in serveraddr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
    };

    if (inet_pton(AF_INET, "0.0.0.0", &serveraddr.sin_addr) < 0)
    {
        ERROR(inet_pton)
    }

    if ( (serverfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        ERROR(sockfd = socket)
    }

    if (connect(serverfd, SA(serveraddr), sizeof(serveraddr)) < 0)
    {
        ERROR(connect)
    }

    while ( (n = read(serverfd, buffer, MAX_LINE)) > 0)
    {
        buffer[n] = 0;
        fputs(buffer, stdout);
    }

    close(serverfd);
}