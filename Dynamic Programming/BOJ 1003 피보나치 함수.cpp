#include <cstdio>

int d[40][2], n;

void dp(int n) {
    d[0][0] = 1;
    d[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        dp(n);
        printf("%d %d\n", d[n][0], d[n][1]);
    }
}
