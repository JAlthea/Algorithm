#include <cstdio>
#include <algorithm>
int x, i, d[1000000];
int main()
{
    for (scanf("%d", &x); i<x; i++)
        scanf("%d", &d[i]);
    std::sort(d, d + x);
    for (i=0; i<x; i++)
        printf("%d\n", d[i]);
}
