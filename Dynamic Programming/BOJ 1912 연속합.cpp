#include <bits/stdc++.h>

int n, d[100001];

int main()
{
    d[0] = -1e9;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        scanf("%d", &d[i]);
    for (int i=1; i<=n; i++)
        d[i] = std::max(d[i-1] + d[i], d[i]);
    printf("%d", *std::max_element(d, d + n + 1));
}
