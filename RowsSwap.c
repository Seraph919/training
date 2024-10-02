#include "general.h"
#include <stdio.h>

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void SwapDynamic2Darray(void **arr, unsigned int rowcount)
{
    void *temp;
    for (int i = 0; i < rowcount /2; i++)
    {
        temp = arr[i];
        arr[i] = arr[rowcount - 1 - i];
        arr[rowcount - 1 - i] = temp;
    }
}

int main()
{
    int k = 0, i = 0;
    int **tab = (int **)malloc(sizeof(int *) * 4);
    if (!tab) return 0;
    for (i = 0; i < 4; i++)
    {
        tab[i] = (int *)malloc(sizeof(int) * 3);
        if (!tab[i])
        {
            while (i)
            {
                free(tab[i--]);
            }
            return 0;
        }
        if (i % 2 == 0)
            for (k = 0; k < 3; k++)
            {
                tab[i][k] = k + 1;
            }
        else
            for (k = 0; k < 3; k++)
            {
                tab[i][k] = k + 2;
            }
    }
    print1DArray(3, tab[0]);               // 1  2  3  
    print1DArray(3, tab[1]);              // 2  3  4   
    print1DArray(3, tab[2]);             // 1  2  3    
    print1DArray(3, tab[3]);            // 2  3  4 
    
    printf("\n");

    SwapDynamic2Darray((void **)tab, 4);

    print1DArray(3, tab[0]);               // 2  3  4   
    print1DArray(3, tab[1]);              // 1  2  3
    print1DArray(3, tab[2]);             // 2  3  4 
    print1DArray(3, tab[3]);            // 1  2  3
    
    return 0;
}