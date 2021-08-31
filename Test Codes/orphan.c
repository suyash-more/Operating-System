#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


/*
ORPHAN

A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to 
terminate is called an orphan process.

In the following code, parent finishes execution and exits while the child process is still executing and is called an orphan process now.

*/

int main(void){
    // Fork returns process id
    // in parent process
    printf("ID of the Parent Process : %d\n", getpid());
    pid_t return_value_fork = fork();
    /*
        fork() This  function creates a new process. The return value is the zero in the child and the process-id number of
              the child in the parent, or -1 upon error. In the latter case, ERRNO indicates the problem.  In  the  child,
              PROCINFO["pid"] and PROCINFO["ppid"] are updated to reflect the correct values.

        waitpid()
                This function takes a numeric argument, which is the process-id to wait for. The return value is that of the
                waitpid(2) system call.

        wait() This function waits for the first child to die.  The return value is that of the wait(2) system call.

        So if child process is created
            fork return 0
        And if not created 
            forn return -1
        

    */

    // Parent process has is being executed
    if (return_value_fork > 0){
        printf("ID of the forked Parent Process : %d\n", getpid());
        printf("The Parent process excited and exited..!!\n");
        exit(0);  
    }
      
  
    // Child process is being executed
    else{
        printf("ID of the forked Child Process : %d\n", getpid());
        printf("Child process started execution..!!\n");
        sleep(20); 
        printf("Child process finished the process now..!!\n");    
    }
    /*
    To demo the parent process status
    open a new terminal while the code is running 
    type in the command = ps -a1
    The status will be O in case of orphan process
    */
    return 0;
}