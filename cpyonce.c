#include "general.h"

int *create_no_duplicated(int *tab, int *size)
{
    int count = 0;
    int d = 0;
    int seen[256] = {0};
    for (int i = 0; i < *size -1; i++)
    {  
        if (tab[i] != tab[i + 1])
            count++;
    }
    int *returned = (int *) malloc(sizeof(int) * count);
    if (!returned) return NULL;
    
    for (int i = 0; i < *size; i++)
    {
        if (!seen[tab[i]])
        {
            seen[tab[i]] = 1;
            returned[d++] = tab[i];
        }
    }
    *size = count;
    return returned;
}
int main()
{
    int tab[10] = {1,2,2,2,5,5,6,7,8,8};
    int size = 11;
    int *ptr = create_no_duplicated(tab, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", ptr[i]);
    }
}