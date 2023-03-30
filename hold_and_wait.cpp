#include "hw4_src/philosopher.hpp"

void* philosopher(void* args)
{
    diners_t* diner = (diners_t*)args;

    sem_t& left_fork = left(diner);
    sem_t& right_fork = right(diner);

    pthread_mutex_lock(&(diner->mutex));
    sem_wait(&left_fork);
    sem_wait(&right_fork);
    eat(diner);
    sem_post(&right_fork);
    sem_post(&left_fork);
    pthread_mutex_unlock(&(diner->mutex));

    return NULL;
}
