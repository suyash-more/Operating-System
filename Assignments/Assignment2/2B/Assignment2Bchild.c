#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
  
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        return binarySearch(arr, mid + 1, r, x);
    }
  
    return -1;
}

int binary_search(int argument_count, char *argument_array[], int *integer_array, int key)
{
    for (int i = 0; i < argument_count; i++)
    {
        *(integer_array + i) = atoi(argument_array[i]);
    }
    return binarySearch(integer_array, 0, argument_count, key);
}

int main(int argc, char* argv[],char *envp[]){
    int count=0, i=0;
    int findnum;
    int *integer_array = (int *)malloc(argc * sizeof(int));
    printf("\nYou are in the Child process Now..!!\n");
    
    printf("The reversed sorted array is : ");
    for(i=0; i<argc;i++){
        if(strcmp(argv[i],"0")==0 && count<1){
                count++;
                continue;
            }
        else
            printf("%s ", argv[argc - i]);
    }
    printf("\nEnter the number to find : ");
    scanf("%d", &findnum);
    printf("\n\nBinary search in progress..!!\n\n");
    int result = binary_search(argc, argv, integer_array, findnum);
    if(result!=-1){
    printf("The number is found at %d index as per sorted array\n", result-1);
    }else{
        printf("Number not found..!!\n");
    }
    
    printf("\nChild process Exited..!!\n");
}