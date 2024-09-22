#include "general.h"


void swaps(void **arr1, void **arr2, int size)
{
    void *temp = malloc(size);
    if (!temp)
        fprintf(stderr,"there was an error when allocating space for 'temp'");
        return ;
    memcpy(temp, arr1, size);
    memcpy(arr1, arr2, size);
    memcpy(arr2, temp, size);
    free(temp);
}
int main()
{
    char a[6] = "12345";

    char b[6] = "54321";
    void *pa = a;
    void *pb = b;

    swaps(&pa, &pb, sizeof(a));

    printf("%s\n%s\n", a, b);
}