#include "general.h"

void printingDynamicTringle(int **arr, unsigned int firstRow, int arrSize)
{
    if (firstRow > 1)
        for (int i = firstRow; i > 0; i--)
        {   
            for (int d = 0; d < i; d++)
            {
                printf("%d  ", arr[i][d]);
            }
            printf("\n");
        }
    
    else if (firstRow == 1)
    {
        for (int i = 0; i < arrSize; i++)
        {   
            for (int d = 0; d < i + 1; d++)
            {
                printf("%d  ", arr[i][d]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

int **lower()
{
    int **arr = (int **)malloc(sizeof(int *) * 3);
    if (!arr) return NULL;

    for (int i = 0; i < 3; i++)
    {
        arr[i] = malloc(sizeof(int) * i+1);
        if (!arr[i]) return NULL;
    }
    return arr;
}

int **Upper()
{
    int **arr = (int **)malloc(sizeof(int *) * 3);
    if (!arr) return NULL;

    for (int i = 3; i > 0; i--)
    {
        arr[i] = malloc(sizeof(int) * i);
        if (!arr[i]) return NULL;
    }
    return arr;
}

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int **tab = Upper();
    int **arr= lower();
    printf("\n");
    printingDynamicTringle(tab, 3, 3);
    printf("\n");
    printingDynamicTringle(arr, 1, 3);


    return 0;
}