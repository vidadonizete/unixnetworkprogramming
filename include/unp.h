#ifndef _UNP_H_
#define _UNP_H_

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 2048

#define ERROR(error)                     \
    fprintf(stderr, "Error: %s %d", #error, __LINE__); \
    exit(0);

#endif //_UNP_H_