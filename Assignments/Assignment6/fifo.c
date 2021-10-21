#include<stdio.h>
#include<stdlib.h>

#define FRAME_BUFFER 3

int check_frame_existance(int *frame_status, int frame_number){
    for(int i=0;i<FRAME_BUFFER;i++){
        if(frame_number==*(frame_status+i)){
            return 1;
        }
    }
    return 0;
}

int main(){
    int frame_status[FRAME_BUFFER] = {-1,-1,-1};
    int n,i, pos=0, hits=0, fault=0;
    int status;
    int *reference_sequence;
    printf("Maximum %d frames will be in the buffer\n\n",FRAME_BUFFER);
    printf("Enter the frame number required : ");
    scanf("%d",&n);

    reference_sequence = (int*)malloc(n*sizeof(int));

    printf("Enter the reference sequence required by the CPU : ");
    for(i=0;i<n;i++){
        scanf("%d",reference_sequence+i);
    }
    printf("The reference sequence is as follows : ");
    for(i=0;i<n;i++){
        printf("%d ",*(reference_sequence+i));
    }
    printf("\nThe frame buffer is : ");
    for(i=0;i<n;i++){
        status = check_frame_existance(frame_status, *(reference_sequence+i));
        if(status){
            hits++;
            printf("\n\t");
            for(int j=0;j<FRAME_BUFFER;j++){
                printf(" %d ", frame_status[j]);
            }
            printf("Hit");
        }else{
            fault++;
            frame_status[pos] = *(reference_sequence+i);
            pos = (pos+1)%FRAME_BUFFER;
            printf("\n\t");
            for(int j=0;j<FRAME_BUFFER;j++){
                printf(" %d ", frame_status[j]);
            }
            printf("Fault");
        }

    }

    printf("\n\nPage Faults occured : %d\nPage hits occured : %d", fault, hits);
    printf("\n\nFault rate : %0.2f%%\nHit rate : %0.2f%%", ((double)fault/n)*100, ((double)hits/n)*100);
}
