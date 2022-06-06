//EX4_es02_B

#include <stdio.h>
#include <pthread.h>

void * thread_func (void * p){
    // cast back:
    long n = (long)p;
    printf("This is the thread\n got: %ld\n", n);
    return (void*)(n*2);    // was: return NULL;
}

int main(){
    pthread_t t1,t2;
    long t_num=1;
    pthread_create(&t1, NULL, &thread_func,(void*)t_num);
    t_num=2;
    pthread_create(&t2, NULL, &thread_func,(void*)t_num);

    long ris1, ris2;
    pthread_join(t1,(void*)&ris1);
    printf("Received thread %ld\n",ris1);
    pthread_join(t2, (void*)&ris2);
    printf("Received thread %ld\n",ris2);
    return 0;
}
