#include "hw4_src/producer_consumer.hpp"

#include "stdio.h"

void* producer_thread(void* args)
{
    data_t* data = (data_t*)args;
    buffer_t* buf = data->buf;
    int val = data->val;

    sem_wait(&(buf->sem_empty));
    pthread_mutex_lock(&(buf->mutex));
    put(buf, val);
    pthread_mutex_unlock(&(buf->mutex));
    sem_post(&(buf->sem_full));

    return NULL;
}

void* consumer_thread(void* args)
{
    buffer_t* buf = (buffer_t*)args;
    int* return_val = (int*)malloc(sizeof(int));

    sem_wait(&(buf->sem_full));
    pthread_mutex_lock(&(buf->mutex));
    get(buf, return_val);
    pthread_mutex_unlock(&(buf->mutex));
    sem_post(&(buf->sem_empty));

    return (void*)return_val;
}
