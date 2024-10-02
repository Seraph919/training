#include "general.h"

int *ResArr(int *vul)
{
    int i = 0;
    int size = 2;
    int *tab = (int *)malloc(sizeof(int *) * size);
    if(!tab) return NULL;
    int number;
    printf("enter the %d number : ", i+1);
    scanf("%d", &number);
    if (number == -1)
    {
        free(tab);
        return NULL;
    }
    else
        while ( number != -1)
        {
            if (i == size)
            {
                size += 1;
                tab = realloc(tab, size * sizeof(int));
            }
            tab[i++] = number;
            printf("enter the %d number : ", i+1);
            scanf("%d", &number);
        }
    *vul = i;
    return tab;
}

int main()
{
    int size;
    int *tab = ResArr(&size);
    for(int i = 0; i < size; i++)
    {
        printf("%d  ", tab[i]);
    }
};