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

    free(a);

    return 0;
}

// Error messages from -fanalyzer

// double_free.c: In function ‘main’:
// double_free.c:9:10: warning: dereference of possibly-NULL ‘a’ [CWE-690] [-Wanalyzer-possible-null-dereference]
//     9 |     a[0] = 5;
//       |     ~~~~~^~~
//   ‘main’: events 1-2
//     |
//     |    7 |     int* a = (int*) calloc(4, sizeof(int));
//     |      |                     ^~~~~~~~~~~~~~~~~~~~~~
//     |      |                     |
//     |      |                     (1) this call could return NULL
//     |    8 | 
//     |    9 |     a[0] = 5;
//     |      |     ~~~~~~~~         
//     |      |          |
//     |      |          (2) ‘a’ could be NULL: unchecked value from (1)
//     |
// double_free.c:16:5: warning: double-‘free’ of ‘a’ [CWE-415] [-Wanalyzer-double-free]
//    16 |     free(a);
//       |     ^~~~~~~
//   ‘main’: events 1-4
//     |
//     |    7 |     int* a = (int*) calloc(4, sizeof(int));
//     |      |                     ^~~~~~~~~~~~~~~~~~~~~~
//     |      |                     |
//     |      |                     (1) allocated here
//     |    8 | 
//     |    9 |     a[0] = 5;
//     |      |     ~~~~~~~~         
//     |      |          |
//     |      |          (2) assuming ‘a’ is non-NULL
//     |......
//     |   14 |     free(a);
//     |      |     ~~~~~~~          
//     |      |     |
//     |      |     (3) first ‘free’ here
//     |   15 | 
//     |   16 |     free(a);
//     |      |     ~~~~~~~          
//     |      |     |
//     |      |     (4) second ‘free’ here; first ‘free’ was at (3)