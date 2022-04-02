#include <cstdio>

const int p = 1'500'000;
int d[p + 1] = { 0, 1 };
long long n;

int main() {
    scanf("%lld", &n);
    
    for (int i = 2; i < p; ++i) {
        d[i] = (d[i - 1] + d[i - 2]) % 1000000;
    }
    
    printf("%d", d[n % p]);
}
