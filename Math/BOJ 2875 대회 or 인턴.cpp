#include <bits/stdc++.h>
using namespace std;

//math
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    printf("%d", min(n / 2, min(m, (n + m - k) / 3)));
}

/*
//brute-force
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = n; i >= 0; --i)
    {
        for (int j = m; j >= 0; --j)
        {
            if (i == j * 2 && n - i + m - j >= k)
            {
                printf("%d", j);
                return 0;
            }
        }
    }
}
*/
