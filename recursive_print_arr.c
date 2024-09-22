#include "general.h"

void recursive_print_arr_start(int *tab, int size)
{
    if (size >= 1)
    {
        printf("%d ", tab[0]);
        recursive_print_arr_start(tab + 1, size - 1);
    }
}

void recursive_print_arr_end(int *tab, int size)
{
        if (size >= 1)
    {
        printf("%d ", tab[size -1]);
        recursive_print_arr_end(tab, size - 1);
    }
}

int main()
{
    int tab1[5] = {9,2,4,3,1};
    recursive_print_arr_start(tab1, 5);
    printf("\n");
    recursive_print_arr_end(tab1, 5);
    printf("\n");
}