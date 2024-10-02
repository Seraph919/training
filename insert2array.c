#include "general.h"

void *insert2array(void *arr, void *value, int index, int size)
{
    char *tab = (char *)malloc ((size + 1) * sizeof(&value));
    if (!tab) return NULL;
    int n = 0;
    for (int i = 0; i < size; i++)
    {
          if (i != index)
          {
               tab[i] = ((char *)arr)[n++];
          }
          else
               tab[i] = value;
    }
    arr = tab;
}

int main()
{
     int tab[3] = {1,2,3};
     int size = 3;
     int value = 5;

     insert2array((void *)tab, &value, 2, size);
     for( int i = 0; i < 4; i++)
     {
          printf("%d ", tab[i]);
     }

}