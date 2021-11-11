#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int pipefds[2];
    int start=0, end;
    int sum1=0,sum2=0;
    int arr[] = {1,2,3,4,5,6};
    int arrsize = sizeof(arr)/sizeof(int);

    if(pipe(pipefds) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if(pid == 0)   // in child process
    {
        start = arrsize/2;
        end= arrsize;
        for(int i=start;i<end;i++){
            sum1+=arr[i];
        }
        close(pipefds[0]); // close read fd
        write(pipefds[1], &sum1, sizeof(sum1));

        printf("Generating sum in child and sending to parent...\n");
        sleep(2); // intentional delay
        exit(EXIT_SUCCESS);
    }

    if(pid > 0)   // in main process
    {
        start = 0;
        end=arrsize/2;
        wait(NULL); // wait for child process to finish
        for(int i=start;i<end;i++){
            sum2+=arr[i];
        }
        close(pipefds[1]); // close write fd
        read(pipefds[0], &sum1, sizeof(sum1));
        close(pipefds[0]); // close read fd
        sum2+=sum1;

        printf("Child sum = %d\nParent sum = %d\nTotal sum = %d", sum1,sum2-sum1,sum2);
    }

    return EXIT_SUCCESS;
}
