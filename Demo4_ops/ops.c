#include <stdio.h>
#include <stdlib.h>

#define CAP 12

void show(const char *title, int a[], int n)
{
    printf("%-8s:", title);
    for (int i = 0; i < n; i++)
        printf(" %3d", a[i]);
    printf("\n");
}

int main(void)
{
    int a[CAP];                           /* місткість 12, зайнято n */
    int n = 10;

    srand(2026);                          /* стале зерно: як у конспекті */
    for (int i = 0; i < n; i++)
        a[i] = rand() % 100;
    show("rand", a, n);

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    printf("sum = %d, average = %.1f\n", sum, (double)sum / n);

    int imin = 0, imax = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[imin]) imin = i;
        if (a[i] > a[imax]) imax = i;
    }
    printf("min a[%d] = %d, max a[%d] = %d\n", imin, a[imin], imax, a[imax]);

    char line[64];
    printf("key = ");
    if (!fgets(line, sizeof line, stdin))
        return 1;
    int key = (int)strtol(line, NULL, 10);
    int pos;
    for (pos = 0; pos < n; pos++)
        if (a[pos] == key)
            break;
    if (pos < n)
        printf("found: a[%d] = %d\n", pos, key);
    else
        printf("not found\n");

    int t = a[imin];                      /* обмін min і max */
    a[imin] = a[imax];
    a[imax] = t;
    show("swap", a, n);

    for (int i = 0, j = n - 1; i < j; i++, j--) {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    show("reverse", a, n);

    int k = 2, v = 77;                    /* вставити v на місце k */
    for (int i = n; i > k; i--)
        a[i] = a[i - 1];
    a[k] = v;
    n++;
    show("insert", a, n);

    k = 0;                                /* видалити елемент k */
    for (int i = k; i < n - 1; i++)
        a[i] = a[i + 1];
    n--;
    show("delete", a, n);
    return 0;
}
