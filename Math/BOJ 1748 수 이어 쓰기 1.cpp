#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d = 1;
    int ret = 0;
    int digit = 1;
    while (n >= digit)
    {
        if (n >= digit * 10) ret += (digit * 10 - digit) * d;
        else ret += (n - digit + 1) * d;
        ++d;
        digit *= 10;
    } 
    cout << ret;
}
