#include <cstdio>
int d[10001], x, n;
int main()
{
    scanf("%d", &x);
    while (x--)
        scanf("%d", &n), d[n]++;
    for (n=1; n<10001; n++)
        if (d[n])
            while (d[n]--)
                printf("%d\n", n);
}
