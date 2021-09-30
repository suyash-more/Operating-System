#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

char message[100] = "This is message from thread ";
char con[10] = " ";

void *thread_function(void *args)
{
    char *msg = (char *)args;
    printf("The arguments provided are : %s \n", msg);
    sleep(5);
    //strcpy(message, "Enjoy the further process..!!\n");
    pthread_exit("Thread executed successfully..!!\n");
}

int main()
{
    int n = 4, thread_status[4];
    pthread_t thread_id[4];
    printf("Thread Creation in progress..!!\n");
    for (int i = 0; i < 4; i++)
    {
        // strcpy(con, "");
        sprintf(con, "%d", (i+1));
        strcat(message, con);
        thread_status[i] = pthread_create(&thread_id[i], NULL, thread_function, (void *)message);
        printf("Thread %d returned : %d\n", (i + 1), thread_status[i]);
        if (thread_status[i] != 0)
        {
            perror("\nError in creating Thread..!!\n");
            exit(0);
        }
        strcpy(message, "This is message from thread ");
    }
    printf("\nNow Joining the threads..!!\n");
    for (int i = 0; i < 4; i++)
    {
        sprintf(con, "%d", (i+1));
        strcat(message, con);
        //pthread_join(thread_id[i], NULL);
        strcpy(message, "This is message from thread ");
    }
    printf("The message now is : %s\n", message);
    return 0;
}