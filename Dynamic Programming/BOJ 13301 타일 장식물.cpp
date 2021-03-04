#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a = 1, b = 1, t;
    for (int i = 3; i <= n; ++i)
    {
        t = b;
        b = a + b;
        a = t;
    }
    if (n == 1) cout << 4;
    else if (n == 2) cout << 6;
    else cout << 2 * a + 4 * b;
}
