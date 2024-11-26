#ifndef __GEN_H__
#define __GEN_H__
#include <stdio.h>

typedef char* data_t;

const int SIZE_FILENAME = 100;
const int SIZE_COMMAND  = 256;

struct a{
    data_t data_node;
    struct a* no;
    struct a* yes;
    struct a* otets;
} typedef node_t;

#endif //__GEN_H__