#include <stdio.h>

int sum(int a[], int n)
{
    printf("sum : sizeof a = %zu\n", sizeof a);
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s;
}

int main(void)
{
    int a[5] = { 10, 20, 30, 40, 50 };
    double d[3] = { 0.5, 1.5, 2.5 };
    char c[3] = { 'x', 'y', 'z' };

    for (int i = 0; i < 5; i++)
        printf("&a[%d] = %p   a[%d] = %d\n", i, (void *)&a[i], i, a[i]);
    printf("a     = %p\n\n", (void *)a);

    for (int i = 0; i < 3; i++)
        printf("&d[%d] = %p   &c[%d] = %p\n", i, (void *)&d[i], i, (void *)&c[i]);
    printf("\n");

    printf("main: sizeof a = %zu\n", sizeof a);
    printf("sum = %d\n\n", sum(a, 5));

    int big[1000];
    for (int i = 0; i < 1000; i++)
        big[i] = i;
    printf("sum 0..999 = %d\n", sum(big, 1000));
    return 0;
}
