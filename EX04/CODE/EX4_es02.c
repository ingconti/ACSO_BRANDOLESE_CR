//EX4_es02
#include <stdio.h>
#include <pthread.h>

void * thread_func (void * p){
    // cast back:
    long n = (long)p;
    printf("This is the thread\n got: %ld\n", n);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    long t_num=1;
    pthread_create(&t1, NULL, &thread_func,(void*)t_num);
    t_num=2;
    pthread_create(&t2, NULL, &thread_func,(void*)t_num);

    pthread_join(t1,(void*)&t_num);
    printf("Received thread %ld\n",t_num);
    pthread_join(t2, (void*)&t_num);
    printf("Received thread %ld\n",t_num);
    return 0;
}
