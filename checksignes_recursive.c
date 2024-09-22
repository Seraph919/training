#include "general.h"

int checks(int *tab, int size)
{
    if (size == 1)
        return 1; 
    if (((tab[size-1] * tab[size-2]) >= 0))
        return 0;

    checks(tab, size - 1);
    
}

int main()
{
    int tab[5] = {-1, 2, -3, 4, -5};
    int tab2[5] = {1, -2, -3, -4, 5};

    printf("%d\n", checks(tab,5));
    printf("%d\n", checks(tab2,5));
}