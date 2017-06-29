#ifndef __FATAL__H__
#define __FATAL__H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSIZE 100

/*  this function print error message and terminate program*/ 

void fatal(const char *message)
{
    char error_message[MSGSIZE];
    strcpy(error_message, "[!!] Fatal Error\n");
    strncat(error_message, message, 83);
    perror(error_message);
    exit(1);
}

#endif
