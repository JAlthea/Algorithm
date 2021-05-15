#include <cstdio>
#include <cstring>
int i, j;
int main()
{
    char d[1000001]; memset(d, 0, 1000001); d[1] = 1;
    for (i=2; i*i<1000001; i++)
        if (!d[i])
            for (j=i*i; j<1000001; j+=i)
                d[j] = 1;
    for (scanf("%d%d", &i, &j); i<=j; i++)
        if (!d[i])
            printf("%d\n", i);
}
