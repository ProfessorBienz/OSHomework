#include "hw4_src/philosopher.hpp"

void* philosopher(void* args)
{
    diners_t* diner = (diners_t*)args;

    sem_t& left_fork = left(diner);
    sem_t& right_fork = right(diner);

    if (diner->philosopher % 2)
    {
        sem_wait(&left_fork);
        sem_wait(&right_fork);
        eat(diner);
        sem_post(&right_fork);
        sem_post(&left_fork);
    }
    else
    {
        sem_wait(&right_fork);
        sem_wait(&left_fork);
        eat(diner);
        sem_post(&left_fork);
        sem_post(&right_fork);
    }

    return NULL;
}
