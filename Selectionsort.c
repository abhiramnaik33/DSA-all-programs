#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;  
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;  
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void generateRandomNumbers(int arr[], int n)

{
	int i = 0;
    for ( i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;  
    }
}

int main()
{
    int n,arr[100000];
    printf("Enter number of elements: ");
    scanf("%d", &n);  

    if (n <= 5000)
    {
        printf("Please enter a value greater than 5000\n");
        return 1;  
    }

    generateRandomNumbers(arr, n);


    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();


    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);


   free(arr);
    return 0;
}



