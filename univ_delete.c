#include "general.h"

void *uniDelete(void *arr, unsigned int size, unsigned int index, unsigned int numberofObject ,unsigned int objSize)
{
    char *tab = malloc(size - (objSize * numberofObject));
    if (!tab) return NULL;

    memcpy(tab, arr, index);
    memcpy((char *)tab + index, (char *)arr + (index + (numberofObject * objSize)), size - (index + (numberofObject * objSize)));
    return tab;
}

int main()
{
    int *arr = malloc(sizeof(int) * 10);
    if (!arr) return 0;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }
    arr = uniDelete(arr, 40, 20, 2, 4);
    for (int i = 0; i < 8; i++)
        printf("%d ", arr[i]);
}