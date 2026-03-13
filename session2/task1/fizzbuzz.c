/* A classic mathematical game for children */

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 100; ++i)
    {
        printf("%d -> ", i);
        if (i % 3 == 0 && i % 5 == 0) printf("Fizz Buzz\n");
        else if (i % 3 == 0) printf("Fizz\n");
        else if (i % 5 == 0) printf("Buzz\n");
        else printf("\n");
    }

    return 0;
}
