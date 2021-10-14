#include<stdio.h>
#include<stdlib.h>

int n=3;

typedef struct {
    int allocation[3];
    int max[3];
    int need[3];
    int over;
} process;

int get_safe_process(process *processes, int cpu_work_units[]){
    int j=-1;
    for(int i=0;i<n;i++){
        if(((processes+i)->over==0) && (cpu_work_units[0] >= ((processes+i)->need[0])) && (cpu_work_units[1] >= ((processes+i)->need[1])) && (cpu_work_units[2] >= ((processes+i)->need[2]))){
            j = i;
            return j;
        }
    }
    return j;
}

int main(){
    int safe_processes=0, rounds=0;
    int cpu_work_units[3]={0};
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

    printf("\n\nThe safe Sequence is : ");

    while(safe_processes<n){
        pro_no = get_safe_process(processes, cpu_work_units);
        printf("P%d ->", pro_no);
        if(pro_no!=-1){
            cpu_work_units[0] += (processes+pro_no)->allocation[0];
            cpu_work_units[1] += (processes+pro_no)->allocation[1];
            cpu_work_units[2] += (processes+pro_no)->allocation[2];
            (processes+pro_no)->over = 1;
            safe_processes++;
        }else{
            int j=0;
            printf("\nThe processes do not have enough resources..!!");
            printf("\n\nThe deadlock is occured due to processes - ");
            while(j<n){
                if (((processes+j)->over==0)){
                    printf(" P%d ", (j+1));
                    j++;
                }
            }
            exit(0);
        }
    }
    printf("END\n");
}