#ifndef __ERR__MALLOC__H__
#define __ERR__MALLOC__H__

#include <stdlib.h>

#include "fatal.h"

void* err_malloc(size_t size)
{
    void *ptr;
    ptr = malloc(size);
    if (ptr == NULL)
        fatal("in err_malloc() on memory allocation");
    return ptr;
}

#endif
