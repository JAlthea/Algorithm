#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int k;
        int c[501] = { 0 }, d[501][501] = { { 0 } }, t;
        
        cin >> k;
        for (int i = 1; i <= k; ++i) {
            cin >> t;
            c[i] = c[i - 1] + t;
        }
        
        for (int i = 1; i <= k; ++i) {
            for (int s = 1; s + i <= k; ++s) {
                int e = s + i;
                d[s][e] = INT_MAX;
                
                for (int r = s; r < e; ++r) {
                    d[s][e] = min(d[s][e], d[s][r] + d[r + 1][e] + c[e] - c[s - 1]);
                }
            }
        }
        
        cout << d[1][k] << '\n';
    }
}
