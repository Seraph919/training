#include "general.h"

void p2p(int **ptr, int size)
{
    ptr = malloc(sizeof(int) * size);
}

int main()
{
    int *ptr;
    int size;
    scanf("%d", &size);
    p2p(&ptr, size);
    for (int  i = 0; i < size; i++)
    {
        ptr[i] = 1;
    }
    for (int i = 0; i < size; i++)
        printf("%d\n", ptr[i]);

    return 0;
}
