#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int *arrival_time;
    int *burst_time;
    int *completion_time;
} process;

process give_minimum(int n){
    
}

int main(){
    int n, total_time=0;
    printf("Enter the number of prcesses : ");
    scanf("%d",&n);
    process* processes = (process *)malloc(n * sizeof(process));
    for(int i=0;i<n;i++){
        (processes+i)->arrival_time = (int* )malloc(sizeof(int));
        (processes+i)->burst_time = (int* )malloc(sizeof(int));
        (processes+i)->completion_time = (int* )malloc(sizeof(int));
    }
    for(int i =0;i<n;i++){
        printf("Enter the arrival time of %d process : ",(i+1));
        scanf("%d", ((processes+i)->arrival_time));
        printf("Enter the burst time of %d process : ",(i+1));
        scanf("%d", ((processes+i)->burst_time));
        *((processes+i)->completion_time) = 0;
        total_time += *((processes+i)->burst_time);
    }

    printf("\nInfo of the processes Entered..!!\n");
    for(int i =0;i<n;i++){
        printf("\n\nArrival Time of %d process : %d \n",(i+1),*((processes+i)->arrival_time));
        printf("Burst Time of %d process : %d \n",(i+1),*((processes+i)->burst_time));
    }

    while(total_time >= 0){
        
    }
}