/* Program with a 'double free' memory allocation bug */

#include <stdlib.h>

int main(void)
{
    int* a = (int*) calloc(4, sizeof(int));

    a[0] = 5;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;

    free(a);

    free(a); // freeing 'a' again causes a 'double free' error

    return 0;
}
