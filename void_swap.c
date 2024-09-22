#include "general.h"

void swaps(void *a, void *b)
{
    int size = sizeof(a);
     void *temp = malloc(sizeof(a));
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);

}

int main()
{
    double k = 10.3124;
    double  i = 312.3127;
    double *a = &i;
    double *b = &k;
    printf("%f  %f\n",*a,*b);
    swaps(a, b);
    printf("%f  %f",*a,*b);

}