#include <bits/stdc++.h>

int n, a, b, t;

inline int M(int n) { return n > 15745 ? n % 15746 : n;}

int main()
{
    scanf("%d", &n);
    a = 1;
    b = 2;
    for (int i=3; i<=n; ++i)
    {
        t = b;
        b += a;
        a = t;
        b = M(b);
    }
    printf("%d", n - 1 ? M(b) : 1);
}
