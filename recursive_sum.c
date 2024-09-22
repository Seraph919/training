#include "general.h"

int recu_sum(int *tab, int size)
{
    if (size == 1)
        return tab[0];

    int sum = tab[0] + recu_sum(tab + 1, size - 1);
    return sum;
}

int main()
{
    int tab[3] = {1,3,3};
    printf("%d\n", recu_sum(tab,3));
}