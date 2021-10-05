#include <stdio.h>
int n=4;
typedef struct process{
    int process_no;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time,completion_time, turnaround_time, wait_time;
    int over;
} process;

int giveHighestProcess(process *processes, int current_time){
    int max=0, j=-1;
    
    for(int i=0;i<n;i++){
        if(((processes+i)->priority > max) && ((processes+i)->over != 1) && ((processes+i)->arrival_time <= current_time)){
            max = (processes+i)->priority;
            j = i;
        }
    }
    
    return j;
}

int main()
{

    int completed_processes=0, current_time=0,total_turnaround_time=0, total_waiting_time=0;
    process processes[4];
    for(int i=0;i<n;i++){
        printf("Enter the Arrival time : ");
        scanf("%d", &(processes[i].arrival_time));
        printf("Enter the Burst Time : ");
        scanf("%d", &(processes[i].burst_time));
        printf("Enter the priority number : ");
        scanf("%d", &(processes[i].priority));
        processes[i].turnaround_time = 0;
        processes[i].start_time = 0;
        processes[i].completion_time = 0;
        processes[i].wait_time = 0;
        processes[i].over = 0;
    }
    
    printf("\n\nNon-Preemptive Priority Scheduling Algorithm\n\n");
    
    int pro_no = 0;
    printf("\n\t\tGantt chart\n\t\t");
    while(completed_processes!=4){
        pro_no = giveHighestProcess(processes, current_time);

        if(pro_no != -1){
            printf("P%d  ", pro_no);
            (processes+pro_no)->start_time = current_time;
            (processes+pro_no)->completion_time = (processes+pro_no)->start_time + (processes+pro_no)->burst_time;
            (processes+pro_no)->turnaround_time = (processes+pro_no)->completion_time - (processes+pro_no)->arrival_time;
            (processes+pro_no)->wait_time = (processes+pro_no)->turnaround_time - (processes+pro_no)->burst_time;
            (processes+pro_no)->over = 1;
            current_time = (processes+pro_no)->completion_time;
            completed_processes++;
            total_turnaround_time += (processes+pro_no)->turnaround_time;
            total_waiting_time += (processes+pro_no)->wait_time;
        }else{
            current_time++;
        }
    }
    
    printf("\n\nPro_no\t\tAT\t\tBT\t\tPri\t\tST\t\tCT\t\tTAT\t\tWT\n");
    
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", (i+1), (processes+i)->arrival_time, (processes+i)->burst_time, (processes+i)->priority, (processes+i)->start_time,(processes+i)->completion_time, (processes+i)->turnaround_time, (processes+i)->wait_time);
    }
    printf("\n\nAvg Turnaround Time is :%0.2f", (double)total_turnaround_time/n);
    printf("\nAvg Waiting Time is : %0.2f", (double)total_waiting_time/n);
    return 0;
}