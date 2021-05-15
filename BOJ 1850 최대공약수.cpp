#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    for (int i = 0; i < __gcd(a, b); ++i)
        cout << 1;
}
