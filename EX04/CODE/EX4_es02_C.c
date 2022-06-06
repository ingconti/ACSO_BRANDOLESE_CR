//EX4_es02_C

#include <stdio.h>
#include <pthread.h>

void * thread_func (void * p){
    // cast back:
    long n = (long)p;
    printf("thread got: %ld\n", n);
    return (void*)(n*2);    // was: return NULL;
}

#define MAX_THREADS 10

int main(){
    pthread_t t[MAX_THREADS];
    long t_num=0;
    for (t_num=0; t_num<=MAX_THREADS; t_num++)
        pthread_create(&t[t_num], NULL, &thread_func,(void*)t_num);
    
    for (t_num=0; t_num<=MAX_THREADS; t_num++){
        long ris;
        pthread_join(t[t_num],(void*)&ris);
        printf("Received from thread %ld\n",ris);
    }
    
    return 0;
}
