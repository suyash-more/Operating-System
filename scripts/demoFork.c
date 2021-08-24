#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void swap(int *number1, int *number2)
{
	int temp = *number1;
	*number1 = *number2;
	*number2 = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	for (i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		swap(&arr[min_idx], &arr[i]);
	}
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)      
  
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
    int state=0,choice=1;

    printf("Press 1 : Demonstrate Zombie Process\nPress 2 : Demonstrate Orphan Process\nChoice :");
    scanf("%d", &choice);
    if(choice==1){
        state=1;
    }
    else{
        state=0;
    }
    pid_t pid_no  = fork();
    
    if(pid_no<0){
        printf("Child process could not be formed\n");
        exit(0);
    }
    else if (pid_no>0){

        printf("The process is in Parent Call\n");
        if(state==1){
            printf("Zombie State Demonstration\n");
            sleep(7);
            selectionSort(arr, n);
            printf("Sorted array using Selection Sort (Parent Process): \n");
            printArray(arr, n);
        }
        else{
            printf("Parent Process Execution Over\n");
            exit(0);
        }
    }
	else{
        if(state==1){
            printf("Child Process Execution Over\n");
            exit(0);
        }
        else{
            printf("Orphan State Demonstration\n");
            sleep(7);
            bubbleSort(arr, n);
            printf("Sorted array using Selection Sort (Child Process): \n");
            printArray(arr, n);
            exit(0);
        }
    }
	
	return 0;
}
