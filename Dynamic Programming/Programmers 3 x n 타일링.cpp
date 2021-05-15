#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    long long a = 3, b = 0, sub = 2;
    
    for (int i=4; i<=n; i+=2)
    {
        b = a;
        a = 3 * a + sub;
        sub = 2 * b + sub;
        if (a > 1000000006)
            a %= 1000000007;
        if (sub > 1000000006)
            sub %= 1000000007;
    }
    
    return a;
}
