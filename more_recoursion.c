#include "general.h"

//this funtion aims to check the array and gives the greatests sum of two numbers that are next to each other in  a given array
int recursive_max_adj(int *tab, int size)
{
    int max;
    if (size <= 2)
        return tab[0] + tab[1];
    int sum = tab[0] + tab[1];
    
    // macro solution
    //max = (recursive_max_adj(++tab, --size) > sum)? recursive_max_adj(++tab, --size) : sum;
    
    // the allowed one:
    max = recursive_max_adj(++tab, --size);
    if (max > sum)
        return max;
    else
        return sum;
}

int main()
{
    int tab1[5] = {9,2,4,3,1};
    int tab2[5] = {3,2,9,5,1};
    printf("%d\n", recursive_max_adj(tab1, 5));
    printf("%d\n", recursive_max_adj(tab2, 5));
}