/* Compile & run this program and observe what happens */

#include <stdio.h>

void assign_values(int x[])
{
    for (int i = 0; i < 100; ++i) // trying to access 100 elements, but only 10 are allocated
    {
        x[i] = (i + 1) * (i + 1);
    }
}

int main(void)
{
    int data[10] = { 0 }; // only 10 elements allocated

    assign_values(data);
    printf("Done!\n");

    return 0;
}
