#include "cs_481_hw_src/src.hpp"

void* compute_pi(void* arg)
{
    thread_data_t* data = (thread_data_t*)(arg);
    int thread_id = data->thread_id;
    calc_t* pi_data = data->pi_calc;

    srand(thread_id * time(NULL));
    

    return NULL;
}

