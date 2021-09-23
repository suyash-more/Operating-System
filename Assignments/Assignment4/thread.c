#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void * thread_function(void *args){
    sleep(2);
    printf("This is the thread function call\n");
}

int main(){
    int thread_creation_status=0;
    pthread_t thread1_id;
    printf("This is before entering the threads\n");

    thread_creation_status = pthread_create(&thread1_id, NULL, thread_function, NULL);

    if(thread_creation_status == 0){
        printf("The thread is successfully created..!!\n");
    }else{
        printf("Problem occured in thread creation..!!\n");
        exit(0);
    }
    printf("The parent thread is joining the thread created..!!\n");
    pthread_join(thread1_id, NULL);
    printf("The thread is joined henceforth. \n");
    return 0;

}