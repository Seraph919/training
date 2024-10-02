#include "general.h"

int  *int2array(int *arr, int size, int value, int index)
{
    int *tab = (int *)malloc(sizeof(int) * size + 1);
    if (!tab) return NULL;
    int n = 0;
    for (int i = 0; i< size +1; i++)
    {
        if (i == index)
        {
            tab[i] = value;
            continue;
        }
        tab[i] = arr[n++]; 
    }
    return tab;
}

int main()
{
     int tab[3] = {1,2,3};
     int size = 3;
     int value = 5;

     int *newarr = int2array(tab, size, value, 3);
     for( int i = 0; i < 4; i++)
     {
          printf("%d ", newarr[i]);
     }

}