#include <bits/stdc++.h>
using namespace std;

long long d[2001][2001], n, k, mod;

long long binomial(long long n, long long k)
{
    if (n < k) return 0;
    if (k == 0 || n == k) return 1;
    long long &ret = d[n][k];
    if (ret != -1) return ret;
    ret = binomial(n - 1, k - 1) % mod + binomial(n - 1, k) % mod;
    return ret %= mod;
}
 
int main()
{
    memset(d, -1, sizeof(d));
    cin >> n >> k >> mod;
    long long ret = 1;
    while (n || k)
    {
        ret *= binomial(n % mod, k % mod);
        ret %= mod;
        n /= mod;
        k /= mod;
    }
    cout << ret;
}
