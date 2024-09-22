#include "general.h"

int *rearray()
{
    int size = 2;
    int i = 0;
    int number;
    int *tab = malloc(sizeof(int) * size);
    if (!tab) return NULL;

    scanf("%d",&number);
    if (number == -1)
        return NULL;
    else
        while (number != -1)
        {
            tab[i++] = number;
            if (i == size)
            {
                size += 1;
                tab = realloc(tab,size);
            }
            scanf("%d", number);
        }
        return tab;

}


int main()
{
    int *tab = malloc(sizeof(int));
    if (!tab) return 0;
    rearray(tab);
}