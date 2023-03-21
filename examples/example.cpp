#include "cs_481_hw_src/src.hpp"

#include <sys/wait.h>
#include <sys/time.h>
#include <cmath>

double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

int main(int argc, char* argv[])
{
    int num_samples = 10000000;
    for (int i = 0; i < 9; i++)
    {
        int num_threads = pow(2, i);
        double t0 = get_time();
        double pi = pthread_compute_pi(num_threads, num_samples);
        double tfinal = get_time() - t0;
        printf("PI Approximation : %e, Time to compute: %e, Num Threads %d, Num Samples %d\n", pi, tfinal, num_threads, num_samples);
    }
}
