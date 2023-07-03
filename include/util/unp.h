#ifndef _UNP_H_
#define _UNP_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <errno.h>

#define MAX_LINE 2048

#define ERROR                                   \
    fprintf(stderr, "Error: %d %d", __LINE__, errno); \
    exit(0);

#define SA(sockaddr) (__CONST_SOCKADDR_ARG) & sockaddr

#endif //_UNP_H_