#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
    fork(); // this will create a child process 
    /*
    In total there will be child processes and a parent process controlling them.
    If number of fork calls = n

    total processes = 2^n
    number of child processes = 2^n - 1
    number of parent process = 1

    i.e. 2^n = 2^n - 1 + 1

    suppose n = 2

                parent
                  /\
                 /  \
                /    \
            child1   parent
               /\         /\
              /  \       /  \
        child3   child4 /    \
                     child2   parent
    
    */
    printf("This is the forked process with ID : %d\n",getpid());
}