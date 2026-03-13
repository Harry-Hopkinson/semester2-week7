#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j;
    float static_array[10];
    int* dyn_array;

    for (i = 0; i < 10; ++i)
    {
        static_array[i] = 0.5f;
    }

    printf("static_array[0] = %f\n", static_array[0]);

    printf("Performing malloc...\n");

    dyn_array = malloc(20*sizeof(int));

    if (dyn_array != NULL)
    {
        for (j = 0; j < 20; ++j)
            printf("dyn_array[%d] = %d\n", j, dyn_array[j]);
        
        free(dyn_array);
    }

    return 0;
}
