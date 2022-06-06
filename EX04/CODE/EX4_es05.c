#define _GNU_SOURCE
#include <assert.h>
#include <sched.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// LINUX ONLY

void * thread_func (void * p){
    int cpu = sched_getcpu();
    pthread_t t_id = pthread_self();
    printf("Th id %d  - on CPU: %d\n",t_id, cpu);
    return NULL;
}


int  main(void)
{
    pthread_t t1,t2;
    long t_num=1;
    pthread_create(&t1, NULL, &thread_func,(void*)t_num);
    t_num=2;
    pthread_create(&t2, NULL, &thread_func,(void*)t_num);
    pthread_join(t1,NULL);
    pthread_join(t2, NULL);

    printf("DONE!\n");
}
