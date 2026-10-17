#include <stdio.h>
#include <stdlib.h>

#define N 5

int g[N];                                 /* глобальний масив */

int main(void)
{
    int a[N] = { 10, 20, 30, 40, 50 };    /* повний ініціалізатор */
    int b[N] = { 1, 2 };                  /* частковий: решта - нулі */
    int c[] = { 7, 8, 9 };                /* розмір - з ініціалізатора */
    int u[N];                             /* без ініціалізації */
    char s[] = "Hi";                      /* рядок */

    printf("a :");
    for (int i = 0; i < N; i++) printf(" %d", a[i]);
    printf("\nb :");
    for (int i = 0; i < N; i++) printf(" %d", b[i]);
    printf("\nc :");
    for (int i = 0; i < (int)_countof(c); i++) printf(" %d", c[i]);
    printf("\ng :");
    for (int i = 0; i < N; i++) printf(" %d", g[i]);
    printf("\nu :");
    for (int i = 0; i < N; i++) printf(" %08X", u[i]);
    printf("\n\n");

    printf("sizeof a    = %zu\n", sizeof a);
    printf("sizeof a[0] = %zu\n", sizeof a[0]);
    printf("elements    = %zu\n", sizeof a / sizeof a[0]);
    printf("_countof(c) = %zu\n\n", _countof(c));

    printf("s = \"%s\", sizeof s = %zu, codes:", s, sizeof s);
    for (int i = 0; i < (int)sizeof s; i++) printf(" %d", s[i]);
    printf("\n");
    return 0;
}
