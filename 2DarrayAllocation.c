#include "general.h"

void printing(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", tab[i]);
    }   
}
int main()
{
    int n = 0;
    int **arr = malloc(3 * sizeof(int *));
    if (!arr) return 0;

    for (int i = 0; i < 3; i++)
    {   
        n = 0;
        arr[i] = malloc(5 * sizeof(int));
        for (n = 0; n < 5; n++)
            arr[i][n] = n+1;
    }
    printing(arr[0], 5);
    printf("\n");
    printing(arr[1], 5);
    printf("\n");
    printing(arr[2], 5);

    free(arr);
    return 0;
}