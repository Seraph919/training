#include "general.h"

void SwapRows(void *row1, void *row2, unsigned int size, unsigned int datasize)
{
    void *temp = malloc(size * datasize);
    memcpy(temp, row1, size * datasize);
    memcpy(row1, row2, size * datasize);
    memcpy(row2, temp, size * datasize);
}

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int **arr = (int **)malloc(sizeof(int *) * 2);
    if (!arr)
    {
        fprintf(stderr, "the 2D array allocation failed");
        free(arr);
        return 0;
    }
    for (int i = 0; i < 2; i++)
    {
        int k = 0;
        arr[i] = malloc(sizeof(int) * 2);
        if (!i % 2)
            for (k = 0; k < 2; k++)
            {
                arr[i][k] = k + 1;
            }
        else
            for (k = 0; k < 2; k++)
            {
                arr[i][k] = k + 2;
            }
    }
    print1DArray(2, arr[0]);
    print1DArray(2, arr[1]);
    SwapRows(arr[0], arr[1], 2, 4);
    print1DArray(2, arr[0]);
    print1DArray(2, arr[1]);
}