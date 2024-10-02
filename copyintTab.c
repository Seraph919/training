#include "general.h"

void copyTab(int *tab, unsigned int size, int **dest)
{
    int *tabl = malloc(sizeof(int) * size);
    if (!tabl) return;

    for (int i = 0; i < size ; i++)
    {
        tabl[i] = tab[i];
    }
    *dest = tabl;
}

int main()
{
    int size = 10;
    int tab[10] = {1,2,3,4,5,6,7,8,9,10};
    int *newtab;
    copyTab(tab, 10, &newtab);
    for (int i = 0; i < 10; i++)
        printf("%d ", newtab[i]);

}