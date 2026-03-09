/* Undefined behaviour example */

#include <stdio.h>

int main(void)
{
    int i, j; // i and j are not declared so are random values in memory

    j = i + 3;

    printf("%d\n", j);

    return 0;
}
