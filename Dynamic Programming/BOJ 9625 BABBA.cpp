#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    
    int a = 0, b = 1, t;
    for (int i = 2; i <= k; ++i)
    {
        t = b;
        b = a + b;
        a = t;
    }
    
    if (k == 1) cout << "0 1";
    else if (k == 2) cout << "1 0";
    else cout << a << ' ' << b;
}
