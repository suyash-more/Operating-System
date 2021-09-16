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

process give_minimum_process(process *processes, int n, int pass_time, int total_time)
{
    // int arrivaltime = INT_MAX;
    int bursttime = INT_MAX;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if((*((processes + i)->burst_time)) <= 0){
            (*(processes + i)->over) = true;
        }else if ((*((processes + i)->over)) == false){
            (*((processes + i)->completion_time))++;
            (*((processes + i)->turnaround_time)) = (*((processes + i)->completion_time)) - (*((processes + i)->arrival_time));
            (*((processes + i)->waiting_time)) = (*((processes + i)->turnaround_time)) - (*((processes + i)->copy_burst_time));
        }
        if ((*((processes + i)->over)) == false)
        {
            if ((*((processes + i)->arrival_time) <= (pass_time - total_time)) && *((processes + i)->burst_time) < bursttime && *((processes + i)->burst_time) > 0)
                {
                    bursttime = *((processes + i)->burst_time);
                    j = i;
                }
        }
    }
    return *(processes + j);
}

int main()
{
    int n, total_time = 0, pass_time=0;
    double avg_waiting_time=0.0, avg_turnaround_time=0.0;
    printf("Enter the number of prcesses : ");
    scanf("%d", &n);
    process *processes = (process *)malloc(n * sizeof(process));
    process p;
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
    
    printf("\nInfo of the processes Entered..!!\n");
    for(int i =0;i<n;i++){
        printf("\n\nArrival Time of %d process : %d \n",(i+1),*((processes+i)->arrival_time));
        printf("Burst Time of %d process : %d \n",(i+1),*((processes+i)->burst_time));
    }
    printf("\t\t\nGantt Chart\t\t\n");
    while(total_time > 0){
        p = give_minimum_process(processes, n, pass_time, total_time);
        printf("P%d ", *(p.name));
        total_time--;
        if(*(p.over) == false){
            *(p.burst_time) = *(p.burst_time) - 1;
        }
    }
    for(int i=0;i<n;i++){
        avg_turnaround_time+= *((processes+i)->turnaround_time);
        avg_waiting_time+= *((processes+i)->waiting_time);
    }
    avg_turnaround_time = avg_turnaround_time / (double)n;
    avg_waiting_time = avg_waiting_time / (double)n;
    printf("\n\n\t\tTable\n\nProcess\t\tArrival Time\t\tBurst Time\t\tCompletion Time\t\tTurnaround Time\t\tWaiting Time\n");
    for(int i=0; i<n;i++){
        printf("P%d\t\t\t%d\t\t%d\t\t\t\t%d\t\t\t%d\t\t\t%d\n",(i+1),*((processes+i)->arrival_time),*((processes+i)->copy_burst_time),*((processes+i)->completion_time),*((processes+i)->turnaround_time),*((processes+i)->waiting_time));
    }

    printf("\n\nAverage Turn Around Time : %.3f\n", avg_turnaround_time);
    printf("Average Waiting Time : %.3f\n", avg_waiting_time);
}