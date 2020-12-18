#include <bits/stdc++.h>
long long t, n, d[101] = {0, 1, 1, 1, 2, 2};
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i=6; i<=n; ++i)
            d[i] = d[i-1] + d[i-5];
        printf("%lld\n", d[n]);
    }
}
