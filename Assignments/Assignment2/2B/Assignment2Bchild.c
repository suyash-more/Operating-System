#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(int argc, char* argv[],char *envp[]){
    int count=0, i=0;
    char* findnum;
    printf("You are in the Child process Now..!!\n");
    
    printf("The sorted array is : ");
    for(i=0; i<argc;i++){
        if(strcmp(argv[i],"0")==0 && count<1){
                count++;
                continue;
            }
        else
            printf("%s ", argv[argc - i]);
    }
    printf("\nEnter the number to find : ");
    scanf("%s", findnum);
    for(i=0; i<argc;i++){
        if(strcmp(argv[i], findnum)==0){
            printf("Number(%s) found at %d index", findnum, i);
            break;
        }
    }
    if(i==argc){
        printf("Number not Found..!!");
    }
    printf("\n");
}