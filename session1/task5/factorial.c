#include <stdio.h>
#include <stdlib.h>

long factorial(int n)
{
    if (n < 0)
    {
        fprintf(stderr, "Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }
    else if (n == 0 || n == 1)
    {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./factorial <value>\n");
        return 1;
    }

    int value = atoi(argv[1]);
    long result = factorial(value);

    printf("%d! = %ld\n", value, result);

    return 0;
}
