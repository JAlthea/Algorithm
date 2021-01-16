#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d", min(n / 2, min(m, (n + m - k) / 3)));
}
