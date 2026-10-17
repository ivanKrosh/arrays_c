#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG 1000000

int data[4] = { 1, 2, 3, 4 };
int limit = 100;                          /* лежить у пам'яті одразу за data */

int sum(int a[])                          /* розмір не передано */
{
    int s = 0;
    for (size_t i = 0; i < sizeof a / sizeof a[0]; i++)
        s += a[i];
    return s;
}

void big_static(void)
{
    static int big[BIG];                  /* 4 МБ у секції даних */
    for (int i = 0; i < BIG; i++)
        big[i] = i;
    printf("static: big[%d] = %d\n", BIG - 1, big[BIG - 1]);
}

void big_heap(void)
{
    int *big = malloc(BIG * sizeof *big); /* 4 МБ у купі */
    if (big == NULL)
        return;
    for (int i = 0; i < BIG; i++)
        big[i] = i;
    printf("heap  : big[%d] = %d\n", BIG - 1, big[BIG - 1]);
    free(big);
}

void big_local(void)
{
    int big[BIG];                         /* 4 МБ у стеку */
    for (int i = 0; i < BIG; i++)
        big[i] = i;
    printf("local : big[%d] = %d\n", BIG - 1, big[BIG - 1]);
}

void overrun(void)
{
    int a[4];
    for (int i = 0; i <= 4; i++)          /* <= замість < */
        a[i] = 0;
    printf("overrun: a[0] = %d\n", a[0]);
}

int main(int argc, char *argv[])
{
    if (argc > 1 && strcmp(argv[1], "stack") == 0) {
        big_static();
        big_heap();
        fflush(stdout);                   /* вивести все до аварії */
        big_local();
        return 0;
    }
    if (argc > 1 && strcmp(argv[1], "overrun") == 0) {
        overrun();
        printf("overrun: returned\n");
        return 0;
    }

    printf("1: limit = %d\n", limit);     /* 1. запис за межу */
    for (int i = 0; i <= 4; i++)
        data[i] = 0;
    printf("1: limit = %d\n", limit);

    int a[5] = { 1, 2, 3, 4, 5 };         /* 2. читання за межу */
    printf("2:");
    for (int i = 0; i <= 5; i++)
        printf(" %d", a[i]);
    printf("\n");

    int ten[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    printf("3: sum = %d\n", sum(ten));    /* 3. sizeof у функції */

    int t[4] = { 5, 3, 8, 6 };            /* 4. невдалий початковий min */
    int mn = 0;
    for (int i = 0; i < 4; i++)
        if (t[i] < mn)
            mn = t[i];
    printf("4: min = %d\n", mn);

    int p[3] = { 1, 2, 3 }, q[3] = { 1, 2, 3 };
    printf("5: p == q ? %s\n", p == q ? "yes" : "no");
    return 0;
}
