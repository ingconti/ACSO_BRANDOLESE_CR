//EX4_es04

#include <stdio.h>
#include <pthread.h>

typedef struct MyPoint{
    int x,y;
}MyPoint;


void * thread_func_Arr (void * p){
    // cast back to string
    char * s = (char*)p;
    printf("got: %s\n", s);
    return NULL;
}
void * thread_func_Struct (void * p){
    // cast back:
    MyPoint * pp = (MyPoint*)p;
    printf( "got: %d %d \n", pp->x, pp->y);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    char msg[] = "HELLO";
    pthread_create(&t1, NULL, &thread_func_Arr,(void*)msg);
    
    MyPoint p = {10,20};
    pthread_create(&t2, NULL, &thread_func_Struct,(void*)&p);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
