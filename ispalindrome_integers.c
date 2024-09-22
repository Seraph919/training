#include "general.h"

int ispalin(int *tab, unsigned int size)
{

    if (size <= 1)
        return 1;

    if (tab[0] != tab[size - 1])
            return 0;
    ispalin(tab + 1, size - 2);
    
}

int main()
{
    int tab[3] = {1,2,1};
    int tab2[5] = {1,2,2,3,1};
    int tab3[5] = {1,2,1,2,1};
    printf("%d\n",ispalin(tab,3));
    printf("%d\n",ispalin(tab2,5));
    printf("%d\n",ispalin(tab3,5));
}
