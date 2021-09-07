#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void swap(int *number1, int *number2)
{
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void sort_array(int argument_count, char *argument_array[], int *integer_array)
{
    for (int i = 0; i < argument_count; i++)
    {
        *(integer_array + i) = atoi(argument_array[i]);
    }
    selectionSort(integer_array, argument_count);
}

int main(int argc, char *argv[])
{
    int *integer_array;
    char **character_array;
    pid_t pid = fork();
    if (argc <= 1)
    {
        printf("\nArguments were not provided so no Sorting Will take place..!!\n\n");
    }
    else
    {
        if (pid == 0)
        {
            integer_array = (int *)malloc(argc * sizeof(int));
            character_array = malloc(argc * sizeof(char *));
            for (int i = 0; i < argc; i++)
            {
                character_array[i] = malloc(10 * sizeof(char));
            }
            printf("Sorting the array..!!\n");
            sort_array(argc, argv, integer_array);
            for (int i = 0; i < argc; i++)
            {
                sprintf(*(character_array + i), "%d", *(integer_array + i));
            }
            execve("./child", character_array, NULL);
            wait(NULL);
        }
        else if(pid > 0){
            printf("\n Back to the parent process..!!");
            wait(NULL);
        }
    }
}