#import <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, f[101][101];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            f[i][j] = (i == j ? 0 : 99999999);
    
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> c;
        f[a][b] = min(c, f[a][b]);
    }
    
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    
    for (int i = 1; i <= n; puts(""), ++i)
        for (int j = 1; j <= n; ++j)
            printf("%d ", f[i][j] >= 99999999 ? 0 : f[i][j]);
}
