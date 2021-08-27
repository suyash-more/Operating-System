#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

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

void sort_array(int argument_count, char* argument_array[], int *integer_array){
    for(int i=0;i<argument_count;i++){
        *(integer_array + i) = atoi(argument_array[i]);
    }
    selectionSort(integer_array, argument_count);
}

int main(int argc, char* argv[]){
    int *integer_array;
    if(argc<=1){
        printf("\nArguments were not provided so no Sorting Will take place..!!\n\n");
    }
    else{
    integer_array = (int*)malloc(argc * sizeof(int));
    sort_array(argc, argv, integer_array);
    execv("./child", )
    }
    for(int i=0;i<argc;i++){
        printf("%d\n",*(integer_array + i));
    }
}