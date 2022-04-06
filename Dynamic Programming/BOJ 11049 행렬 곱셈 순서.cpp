#include <bits/stdc++.h>
using namespace std;

int n, t, result[501][501], d[501];

int main() {
    cin >> n >> d[0];
    for (int i = 1; i < n; ++i) {
        cin >> d[i] >> t;
    }
    cin >> d[n];

    for (int i = 1; i <= n; ++i) {
        for (int s = 1; s + i <= n; ++s) {
            int e = s + i;
            result[s][e] = INT_MAX;
            
            for (int c = s; c < e; ++c) {
                result[s][e] = min(result[s][e], result[s][c] + result[c + 1][e] + d[s - 1] * d[c] * d[e]);
            }
        }
    }

    cout << result[1][n];
}
