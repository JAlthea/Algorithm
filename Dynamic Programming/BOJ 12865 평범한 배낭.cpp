#include <bits/stdc++.h>
using namespace std;

int n, k, d[101][100001], w[101], v[101];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> v[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            d[i][j] = d[i - 1][j];
            
            if (j >= w[i]) {
                d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    
    cout << d[n][k];
}
