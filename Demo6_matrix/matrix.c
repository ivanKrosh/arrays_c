#include <stdio.h>

#define ROWS 3
#define COLS 4

void show(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);
    printf("\n");
}

int main(void)
{
    int m[ROWS][COLS] = {
        { 11, 12, 13, 14 },
        { 21, 22, 23, 24 },
        { 31, 32, 33, 34 },
    };

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            printf(" %4d", m[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("sizeof m       = %zu\n", sizeof m);
    printf("sizeof m[0]    = %zu\n", sizeof m[0]);
    printf("sizeof m[0][0] = %zu\n\n", sizeof m[0][0]);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            printf("m[%d][%d] = %d   %p   offset %2zu = (%d*%d + %d)*4\n",
                   i, j, m[i][j], (void *)&m[i][j],
                   (size_t)((char *)&m[i][j] - (char *)m), i, COLS, j);
    printf("\n");

    printf("row m[1]:");
    show(m[1], COLS);
    return 0;
}
