//EX4_es01
#include <stdio.h>
#include <pthread.h>

void * thread_func (void * p){
    printf("This is the thread\n");
    return NULL;
}

int main(){
    pthread_t t;
    int i;
    pthread_create(&t, NULL, &thread_func,NULL);
    for(i=0;i<10000; i++){
        //do something
    }
    
    //scanf("%d", &i); // keep main alive..
}
