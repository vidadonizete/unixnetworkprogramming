#include <unp.h>

#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buffer[MAX_LINE + 1];

    struct sockaddr_in serveraddr = {
        .sin_family = AF_INET,
        .sin_port = htons(13),
    };

    if (inet_pton(AF_INET, "0.0.0.0", &serveraddr.sin_addr) < 0)
    {
        ERROR(inet_pton)
    }

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        ERROR(sockfd = socket)
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
    {
        ERROR(connect)
    }

    while ( (n = read(sockfd, buffer, MAX_LINE)) > 0)
    {
        buffer[n] = 0;
        fputs(buffer, stdout);
    }
}