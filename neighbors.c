#include "general.h"

int neighbors(int *tab, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (tab[i] == (tab[i - 1] + tab[i + 1]))
            return 1;
    }
    return 0;
}
int main()
{
    int tab[6] = {1,2,3,5,2,23};
    int tab1[6] = {1,2,3,4,5,6};
    printf("%d\n", neighbors(tab,6));
    printf("%d\n", neighbors(tab1,6));

}