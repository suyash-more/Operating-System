#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char* argv[],char *envp[]){
    int count=0;
    printf("You are in the Child process Now..!!\n\n");
    printf("The sorted array is : ");
    for(int i=0; i<argc;i++){
        if(strcmp(argv[i],"0")==0 && count<1){
                count++;
                continue;
            }
        else
            printf("%s ", argv[argc - i]);
    }
    printf("\n");
}