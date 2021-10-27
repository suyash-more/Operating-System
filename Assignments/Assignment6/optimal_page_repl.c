#include<stdio.h>
#include<stdlib.h>

#define FRAME_BUFFER 4

int get_replacement_index(int *frame_status, int *reference_sequence, int frame_number){

}

int main(){
    int frame_status[FRAME_BUFFER] = {-1,-1,-1,-1};
    int n,i, pos=0, hits=0, fault=0;
    int status;
    int *reference_sequence;
    printf("Maximum %d frames will be in the buffer\n\n", FRAME_BUFFER);
    printf("Enter the frame number required : ");
    scanf("%d",&n);

    reference_sequence = (int*)calloc(n, sizeof(int));

    printf("Enter the reference sequence required by the CPU : ");
    for(i=0;i<n;i++){
        scanf("%d",reference_sequence+i);
    }
    printf("The reference sequence is as follows : ");
    for(i=0;i<n;i++){
        printf("%d ",*(reference_sequence+i));
    }

    for(i=0;i<n;i++){
        pos = get_replacement_index(frame_status, reference_sequence, *(reference_sequence+i));

    }
}
