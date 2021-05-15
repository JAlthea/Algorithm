#include <cstdio>

long long n;
int d[1500001] = { 0, 1 }, p = 1500000;

int main()
{
    scanf("%lld", &n);
    for (int i=2; i<p; ++i)
        d[i] = (d[i - 1] + d[i - 2]) % 1000000;
    int t = (int)(n % 1500000);
    printf("%d", d[t]);
}
