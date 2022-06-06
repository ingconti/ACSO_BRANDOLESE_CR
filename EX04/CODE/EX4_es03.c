//EX4_es03

#include <stdio.h>
#include <pthread.h>

#define MAX 10000
static long shared = 0;

void * thread_func (void * p){
    int i;
    long n = (long)p;
    for (i=0; i<MAX; i++){
        shared+=n;
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
