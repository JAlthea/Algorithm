#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string a, b;
    cin >> a >> b;
    for (int i=1; i<=a.size(); ++i) d[0][i] = i;
    for (int i=1; i<=b.size(); ++i) d[i][0] = i;
    
    for (int i=1; i<=b.size(); ++i)
    {
        for (int j=1; j<=a.size(); ++j)
        {
            if (a[j - 1] == b[i - 1]) d[i][j] = d[i - 1][j - 1];
            else d[i][j] = min(d[i - 1][j], min(d[i][j - 1], d[i - 1][j - 1])) + 1;
        }
    }
    
    cout << d[b.size()][a.size()];
}
