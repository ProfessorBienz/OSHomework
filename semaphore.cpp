#include "cs_481_hw_src/src.hpp"

void* producer_thread(void* args)
{
    data_t* data = (data_t*)args;
    buffer_t* buf = data->buf;
    int val = data->val;

    return NULL;
}

void* consumer_thread(void* args)
{
    buffer_t* buf = (buffer_t*)args;
    int* return_val = (int*)malloc(sizeof(int));

    return (void*)return_val;
}
