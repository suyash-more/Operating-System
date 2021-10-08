#include<stdio.h>
#include<stdlib.h>


int n=5;

typedef struct {
    int allocation[3];
    int max[3];
    int need[3];
    int over;
} process;

int getFeasibleProcess(process *processes, int cpu_work_units[]){
    int j=-1;
    for(int i=0;i<n;i++){
        if(((processes+i)->over!=1) && (cpu_work_units[0] > ((processes+i)->need[0])) && (cpu_work_units[1] > ((processes+i)->need[1])) && (cpu_work_units[2] > ((processes+i)->need[2]))){
            j = i;
            return j;
        }
    }
}

int main(){
    int safe_processes=0;
    int cpu_work_units[3];
    int copy_cpu_work_units[n][3];
    int pro_no=0;
    process processes[n];
    
    for(int i=0;i<n;i++){
        printf("\n\nEnter the Allocation of resources in P%d\n", (i+1));
        printf("\tA : ");
        scanf("%d", &((processes+i)->allocation[0]));
        printf("\tB : ");
        scanf("%d", &((processes+i)->allocation[1]));
        printf("\tC : ");
        scanf("%d", &((processes+i)->allocation[2]));
        
        printf("\n\nEnter the Maximum Allocation that can be provided to P%d\n",(i+1));
        printf("\tA : ");
        scanf("%d", &((processes+i)->max[0]));
        printf("\tB : ");
        scanf("%d", &((processes+i)->max[1]));
        printf("\tC : ");
        scanf("%d", &((processes+i)->max[2]));
        
        (processes+i)->need[0] = (processes+i)->max[0] - (processes+i)->allocation[0];
        (processes+i)->need[1] = (processes+i)->max[1] - (processes+i)->allocation[1];
        (processes+i)->need[2] = (processes+i)->max[2] - (processes+i)->allocation[2];
        
        (processes+i)->over=0;
    }
    
    printf("\n\nEnter the Work units Available\n");
    printf("\tA : ");
    scanf("%d", &cpu_work_units[0]);
    printf("\tB : ");
    scanf("%d", &cpu_work_units[1]);
    printf("\tC : ");
    scanf("%d", &cpu_work_units[2]);
    
    while(safe_processes!=n){
        pro_no = getFeasibleProcess(processes, cpu_work_units);
        printf("%d", pro_no);
        if(pro_no!=-1){
            copy_cpu_work_units[pro_no][0] = cpu_work_units[0]
            copy_cpu_work_units[pro_no][1] = cpu_work_units[1]
            copy_cpu_work_units[pro_no][2] = cpu_work_units[2]
            cpu_work_units[0] += (processes+pro_no-1)->allocation[0];
            cpu_work_units[1] += (processes+pro_no-1)->allocation[1];
            cpu_work_units[2] += (processes+pro_no-1)->allocation[2];
            (processes+pro_no-1)->over = 1;
            safe_processes++;
        }else{
            printf("The process is deadlock state..!!");
            exit(0);
        }
    }
    
    printf("\nPro_no\t\tAllocation\t\tMaximum\t\tAvailable\n");
    printf("      \t\tA B C\t\t\t A B C\t\t\tA B C\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d %d %d\t\t\t%d %d %d\t\t%d %d %d\n",(i+1), (processes+i)->allocation[0],(processes+i)->allocation[1],(processes+i)->allocation[2],(processes+i)->max[0],(processes+i)->max[1],(processes+i)->max[2],copy_cpu_work_units[0], copy_cpu_work_units[1], copy_cpu_work_units[2]);
    }

    
}