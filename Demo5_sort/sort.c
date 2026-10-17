#include <stdio.h>
#include <stdlib.h>

#define N 8
#define BIG 1000

long long cmps, swaps;                    /* лічильники порівнянь і обмінів */

void show(const char *title, int a[], int n)
{
    printf("%-8s:", title);
    for (int i = 0; i < n; i++)
        printf(" %3d", a[i]);
    printf("\n");
}

void bubble(int a[], int n, int verbose)
{
    for (int pass = 1; pass < n; pass++) {
        int swapped = 0;
        for (int i = 0; i < n - pass; i++) {
            cmps++;
            if (a[i] > a[i + 1]) {
                int t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
                swaps++;
                swapped = 1;
            }
        }
        if (verbose) {
            char title[16];
            sprintf_s(title, sizeof title, "pass %d", pass);
            show(title, a, n);
        }
        if (!swapped)                     /* обмінів не було: уже впорядковано */
            break;
    }
}

void selection(int a[], int n, int verbose)
{
    for (int i = 0; i < n - 1; i++) {
        int m = i;                        /* індекс мінімуму в a[i..n-1] */
        for (int j = i + 1; j < n; j++) {
            cmps++;
            if (a[j] < a[m])
                m = j;
        }
        if (m != i) {
            int t = a[i];
            a[i] = a[m];
            a[m] = t;
            swaps++;
        }
        if (verbose) {
            char title[16];
            sprintf_s(title, sizeof title, "step %d", i + 1);
            show(title, a, n);
        }
    }
}

void copy(int dst[], int src[], int n)
{
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

int main(void)
{
    int src[N] = { 42, 7, 93, 15, 61, 3, 78, 29 };
    int a[N];

    show("source", src, N);

    printf("\n--- bubble ---\n");
    copy(a, src, N);
    cmps = swaps = 0;
    bubble(a, N, 1);
    printf("comparisons = %lld, swaps = %lld\n", cmps, swaps);

    printf("\n--- selection ---\n");
    copy(a, src, N);
    cmps = swaps = 0;
    selection(a, N, 1);
    printf("comparisons = %lld, swaps = %lld\n", cmps, swaps);

    static int big[BIG], b[BIG];
    srand(2026);
    for (int i = 0; i < BIG; i++)
        big[i] = rand();

    printf("\n--- %d random numbers ---\n", BIG);
    copy(b, big, BIG);
    cmps = swaps = 0;
    bubble(b, BIG, 0);
    printf("bubble    : comparisons = %7lld, swaps = %6lld\n", cmps, swaps);
    copy(b, big, BIG);
    cmps = swaps = 0;
    selection(b, BIG, 0);
    printf("selection : comparisons = %7lld, swaps = %6lld\n", cmps, swaps);

    printf("\n--- %d numbers, already sorted ---\n", BIG);
    cmps = swaps = 0;
    bubble(b, BIG, 0);
    printf("bubble    : comparisons = %7lld, swaps = %6lld\n", cmps, swaps);
    cmps = swaps = 0;
    selection(b, BIG, 0);
    printf("selection : comparisons = %7lld, swaps = %6lld\n", cmps, swaps);
    return 0;
}
