#include "general.h"

void r(int *arr, int size)
{
    int temp;
    for (int i = 0; i< size / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[size -1];
        arr[size - 1] = temp;
        size--;
    }
}

void swp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recu(int *arr, int size)
{
    if (size > 1)
        return ;
        
    swp(arr, arr + size -1);
        
    recu(arr + 1, size - 2);
}



int main() {
    int d[11] = {1,2,3,3333,5,6,412,123,11,3,5};
    recu(d,11);
    for (int i = 0; i < 11; i++)
        printf("%d  ", d[i]);

    return 0;
}