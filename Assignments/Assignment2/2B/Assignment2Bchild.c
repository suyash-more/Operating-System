#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
    for(int i=0; i<argc;i++){
        printf("%s", argv[i]);
    }
}