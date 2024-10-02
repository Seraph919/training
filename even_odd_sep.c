#include "general.h"

void printing(int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void printsep(int *tab, int size)
{
    int *evens;
    int *odds;
    int odd_count = 0, even_count = 0, k = 0, j = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] % 2)
            even_count++;
        else
            odd_count++;
    }
    evens = (int*) malloc(sizeof(int) * even_count);
    if (!evens) return ;
    odds = (int*) malloc(sizeof(int) * odd_count);
    if (!odds) return ;
    for (int i = 0; i < size; i++)
    {
        if (tab[i] % 2 == 0)
            evens[k++] = tab[i];
        else
            odds[j++] = tab[i];
    }
    printing(evens, k);
    printing(odds, j);
}



int main()
{
    int tab[10] = {1,414,22,3,4,66,78,4,5,7};
    printsep(tab, 10);

}