#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

pthread_mutex_t lock;
long loop_index;

typedef struct {
    long upper_bound;
    int nprimes;
} thread_data_t;

void *calc_primes(void *thread_input_data)
{
    thread_data_t *tdata = (thread_data_t *) thread_input_data;

    while (loop_index <= tdata->upper_bound) {
        int ndivisible = 0;

        pthread_mutex_lock(&lock);  // Lock mutex
        long i = loop_index++;
        pthread_mutex_unlock(&lock);  // Unlock mutex

        for (long j = 1; j < i; j++) {
            if ((i % j) == 0) {
                ndivisible++;
                if (ndivisible > 1) {
                    break;
                }
            }
        }
        if (ndivisible == 1) {
            tdata->nprimes++;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc < 4) {
        fprintf(stderr, "Program requires three positional arguments:\n"
                        "\t0: number of threads\n"
                        "\t1: range: lower limit\n"
                        "\t2: range: upper limit\n");
        return -1;
    }

    struct timespec exec_start, exec_finish;
    clock_gettime(CLOCK_MONOTONIC, &exec_start);

    short nthreads = (short) strtol(argv[1], NULL, 10); // Number of threads
    long lower_bound = strtol(argv[2], NULL, 10); // Lower bound of numbers to check "prime-ness"
    long upper_bound = strtol(argv[3], NULL, 10); // Upper bound of numbers to check "prime-ness"
    loop_index = lower_bound;

    pthread_t threads[nthreads];
    thread_data_t tdata[nthreads];

    for (int i = 0; i < nthreads; i++) {
        tdata[i].upper_bound = upper_bound;
        tdata[i].nprimes = 0;
        if (pthread_create(&threads[i], NULL, calc_primes, &tdata[i])) {
            return -1;
        }
    }

    int nprimes = 0;
    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
        nprimes += tdata[i].nprimes;
    }

    clock_gettime(CLOCK_MONOTONIC, &exec_finish);
    double elapsed = (double) (exec_finish.tv_sec - exec_start.tv_sec) +
                     ((exec_finish.tv_nsec - exec_start.tv_nsec) / (double) 1000000000);

    printf("%d primes found between %ld and %ld in %lf seconds.\n", nprimes, lower_bound, upper_bound, elapsed);

    return 0;
}