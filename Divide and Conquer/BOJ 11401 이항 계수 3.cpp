#include <bits/stdc++.h>
using namespace std;

const long long p = 1000000007;    // Prime nubmer, MOD

long long pow(long long x, long long y) {
    long long result = 1;
    
    while (y > 0) {
        if (y % 2) {    // Odd
            result *= x;
            result %= p;
        }
        
        x *= x;
        x %= p;
        y /= 2;
    }
    
    return result;
}

int main() {
    long long n, k, result = A = B = 1;
    cin >> n >> k;
    
    // A = n!
    for (long long i = 1; i <= n; ++i) {
        A *= i;
        A %= p;
    }
    
    // B = k!(n - k)!
    for (long long i = 1; i <= k; ++i) {
        B *= i;
        B %= p;
    }
    for (long long i = 1; i <= n - k; ++i) {
        B *= i;
        B %= p;
    }
    
    // C = (k!(n - k)!)^(p - 2)
    long long C = pow(B, p - 2);
    result = A * C % p;
    cout << result;
}
