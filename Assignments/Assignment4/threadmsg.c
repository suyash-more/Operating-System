#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void * print_function(void *ptr){
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}

int main(){
    pthread_t thread1_id, thread2_id;
    int thread1_status, thread2_status;
    char *msg1 = "Thread 1 returned and joined\n";
    char *msg2 = "Thread 2 returned and joined\n"; 

    printf("This is before the thread creation..!!\n");


    thread1_status = pthread_create(&thread1_id, NULL, print_function, (void*) msg1);
    thread2_status = pthread_create(&thread2_id, NULL, print_function, (void*) msg2);

    printf("After thread creation..!!\n");

    pthread_join(thread1_id, NULL);
    pthread_join(thread2_id, NULL);
    

    printf("Thread 1 returned : %d\n", thread1_status);
    printf("Thread 2 returned : %d\n", thread2_status);

}