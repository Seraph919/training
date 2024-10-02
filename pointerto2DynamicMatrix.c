#include "general.h"

void pointerto2D(int ***tab)
{
    int **arr = (int **)malloc(sizeof(int *) * 3);
    if (!arr) return ;

    for (int i = 0; i < 3; i++)
    {
        arr[i] = malloc(sizeof(int) * 3);
        if (!arr[i]) return;
        for (int d = 0; d < 3; d++)
        {
            arr[i][d] = 1;       
        }
    }
    *tab = arr;
}

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int **arr;
    pointerto2D(&arr);
    print1DArray(3,arr[0]);
    print1DArray(3,arr[1]);
    print1DArray(3,arr[2]);
    return 0;
}