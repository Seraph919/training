#include "general.h"

void print1DArray(int size, int array[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swapColumns(int **arr, int colnum1, int colnum2, int rows)
{
    int temp;
    for (int i = 0; i < rows; i++)
    {
        temp = arr[i][colnum1];
        arr[i][colnum1] = arr[i][colnum2];
        arr[i][colnum2] = temp;
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
    
    swapColumns(tab,0,1,4);
    printf("\n");

    print1DArray(3, tab[0]);               // 3  3  1  
    print1DArray(3, tab[1]);              // 4  2  2
    print1DArray(3, tab[2]);             // 3  3  1
    print1DArray(3, tab[3]);            // 4  2  2

    return 0;
}