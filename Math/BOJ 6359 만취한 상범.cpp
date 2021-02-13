#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<bool> d(n + 1);
        for (int i=1; i<=n; ++i)
            for (int j=i; j<=n; j+=i)
                d[j] = !d[j];
        
        int ret = 0;
        for (int i=1; i<=n; ++i)
            if (d[i]) ret++;
        cout << ret << '\n';
    }
}
