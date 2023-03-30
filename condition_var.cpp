#include "hw4_src/producer_consumer.hpp"

#include "stdio.h"

void* producer_thread(void* args)
{
    data_t* data = (data_t*)args;
    buffer_t* buf = data->buf;
    int val = data->val;
    pthread_cond_t& full = buf->full;
    pthread_cond_t& empty = buf->empty;
    pthread_mutex_t& mutex = buf->mutex;

    pthread_mutex_lock(&mutex);
    while (buf->size == buf->limit)
        pthread_cond_wait(&empty, &mutex);
    put(buf, val);
    pthread_cond_signal(&full);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void* consumer_thread(void* args)
{
    buffer_t* buf = (buffer_t*)args;
    int* return_val = (int*)malloc(sizeof(int));
    pthread_cond_t& full = buf->full;
    pthread_cond_t& empty = buf->empty;
    pthread_mutex_t& mutex = buf->mutex;

    pthread_mutex_lock(&mutex);
    while (buf->size == 0)
        pthread_cond_wait(&full, &mutex);
    get(buf, return_val);
    pthread_cond_signal(&empty);
    pthread_mutex_unlock(&mutex);

    return (void*)return_val;
}
