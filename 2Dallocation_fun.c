#include "general.h"

int **TwoD_array()
{
    int columns;

    int **arr = malloc(sizeof(int *) * 3);
    if (!arr)
    {
        fprintf(stderr, "the 2D array allocation failed");
        return 0;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("how many columns you want in the %d row ? \n", i + 1);
        scanf("%d", &columns);
        printf("\n");
        arr[i] = malloc(columns * sizeof(int));
        if (!arr[i])
        {
            fprintf(stderr, "the %d array allocation failed",i + 1);
            for (int d = 0; d <= i; d++)
                free(arr[d]);
            return 0;
        }
        for (int k = 0; k < columns; k++)
        {   
            arr[i][k] = k+1;
        }
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
    int **arr = TwoD_array();;
    
    printf("\n");
    print1DArray(1,arr[0]);
    printf("\n");
    print1DArray(2,arr[1]);
    printf("\n");
    print1DArray(3,arr[2]);
    

}