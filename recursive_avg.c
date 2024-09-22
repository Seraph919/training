#include "general.h"


// this logic 

float recu_avg(int *tab, int size)
{
    float avragesofar;
    
    if (size == 1)
        return tab[0];

    avragesofar = recu_avg(tab + 1, size - 1);
    return (avragesofar * (size -1) + tab[0]) / size;
}

int main()
{
    int tab1[6] = {1,2,3,4,5,6};
    printf("%f\n", recu_avg(tab1,6));
}