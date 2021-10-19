#include<stdio.h>
#include<stdlib.h>

int main(){
    int frame_status[3];
    int n,i;
    
    printf("Enter the frame number required : ");
    scanf("%d",&n);

    int *reference_sequence = (int*)calloc(n, sizeof(int));
    printf("Enter the reference sequence required by the CPU : ");
    for(i=0;i<n;i++){
        scanf("%d",(*reference_sequence+i));
    }
    for(i=0;i<n;i++){
        printf("%d",(*reference_sequence+i));
    }
}