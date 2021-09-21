#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

typedef struct
{
    int* name;
    int *arrival_time;
    int *burst_time;
    int *copy_burst_time;
    int *completion_time;
    int *turnaround_time;
    int * waiting_time;
    bool *over;
} process;

process give_next_process(process *processes,int quantum, int pass_time, int total_time){

}

int main(){
    int n, total_time = 0, pass_time=0, quantum=0, pass_no = 0;
    double avg_waiting_time=0.0, avg_turnaround_time=0.0;
    printf("Enter the number of processes : ");
    scanf("%d", &n);
    printf("Enter the quantum : ");
    scanf("%d", &quantum);
    process *processes = (process *)malloc(n * sizeof(process));
    process *p;
    for (int i = 0; i < n; i++)
    {
        (processes + i)->name = (int *)malloc(sizeof(int));
        (processes + i)->arrival_time = (int *)malloc(sizeof(int));
        (processes + i)->burst_time = (int *)malloc(sizeof(int));
        (processes + i)->copy_burst_time = (int *)malloc(sizeof(int));
        (processes + i)->completion_time = (int *)malloc(sizeof(int));
        (processes + i)->turnaround_time = (int *)malloc(sizeof(int));
        (processes + i)->waiting_time = (int *)malloc(sizeof(int));
        (processes + i)->over = (bool *)malloc(sizeof(bool));
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the arrival time of %d process : ", (i + 1));
        scanf("%d", ((processes + i)->arrival_time));
        printf("Enter the burst time of %d process : ", (i + 1));
        scanf("%d", ((processes + i)->burst_time));
        *((processes + i)->copy_burst_time) = *((processes + i)->burst_time);
        *((processes + i)->completion_time) = 0;
        *((processes + i)->turnaround_time) = 0;
        *((processes + i)->waiting_time) = 0;
        *((processes + i)->over) = false;
        *((processes + i)->name) = i+1;
        total_time += *((processes + i)->burst_time);
    }

    pass_time = total_time;

    pass_no = 0;

    printf("\nInfo of the processes Entered..!!\n");
    for(int i =0;i<n;i++){
        printf("\n\nArrival Time of %d process : %d \n",(i+1),*((processes+i)->arrival_time));
        printf("Burst Time of %d process : %d \n",(i+1),*((processes+i)->burst_time));
    }

    while(total_time >= 0){
        printf("inside the loop\n");

        p = (processes + pass_no);
        printf("P%d\n ", *(p->name));
        printf("inside the loop %d\n",*(p->burst_time));
        if(*(p->burst_time) > 0){
            if(*(p->burst_time) > quantum){
                printf("P%d ", *(p->name));
                *(p->burst_time)-=quantum;
                total_time-=quantum;
            }else{
                printf("P%d ", *(p->name));
                total_time-=(*(p->burst_time));
                *(p->burst_time)=0;
            }
            pass_no = ((pass_no%n) + 1)%n;
        }
            pass_no = ((pass_no%n) + 1)%n;
        
    }
}