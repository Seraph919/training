#include "general.h"

// this array should be 1, 2, 2, 3, 3.
// each row should have a specific number of columns.

// we can do it like this :

/*
    arr[0] = malloc(sizeof(int) * 1);
    arr[1] = malloc(sizeof(int) * 2);
    arr[2] = malloc(sizeof(int) * 2);
    arr[3] = malloc(sizeof(int) * 3);
    arr[4] = malloc(sizeof(int) * 3);
*/

// or let the user decide :

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int rows, columns;

    printf("how many rows you want in this array ? \n");
    scanf("%d", &rows);
    printf("\n");

    int **arr = malloc(sizeof(int *) * rows);
    if (!arr)
    {
        fprintf(stderr, "the 2D array allocation failed");
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        printf("how many columns you want in the %d row ? \n", i + 1);
        scanf("%d", &columns);
        printf("\n");
        arr[i] = malloc(columns * sizeof(int));
        if (!arr[i])
        {
            fprintf(stderr, "the %d array allocation failed",i + 1);
            return 0;
        }
        for (int k = 0; k < columns; k++)
        {   
            arr[i][k] = k+1;
        }
        print1DArray(columns,arr[i]);
    }
    printf("\n");

}