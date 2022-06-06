//EX4_es03_FIX_with_mutex.c

#include <stdio.h>
#include <pthread.h>

#define MAX 10000
static long shared = 0;
static pthread_mutex_t mutex= PTHREAD_MUTEX_INITIALIZER;

void * thread_func (void * p){
    int i;
    long n = (long)p;
    for (i=0; i<MAX; i++){
        pthread_mutex_lock(&mutex);
        shared+=n;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t t1,t2;
    long t_num=1;
    pthread_create(&t1, NULL, &thread_func,(void*)t_num);
    t_num=2;
    pthread_create(&t2, NULL, &thread_func,(void*)t_num);
    pthread_join(t1,NULL);
    pthread_join(t2, NULL);
    
    printf("SHARED: %ld\n", shared);

    return 0;
}
