#import <bits/stdc++.h>

int main() {
    int n, s[301] = { 0 };
    int d[301][2] = { { 0 } };
    
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    
    d[1][0] = s[1];
    d[1][1] = 0;
    for (int i = 2; i <= n; ++i) {
        d[i][0] = std::max(d[i - 2][0], d[i - 2][1]) + s[i];
        d[i][1] = d[i - 1][0] + s[i];
    }
    
    printf("%d", std::max(d[n][0], d[n][1]));
}
