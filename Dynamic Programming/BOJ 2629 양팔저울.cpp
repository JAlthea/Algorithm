#include <bits/stdc++.h>
using namespace std;

int n, m, t, w[31];
bool d[31][31001];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        w[i] = t;
    }
    
    d[0][15500] = true;
    d[0][15500 + w[0]] = true;
    d[0][15500 - w[0]] = true;
    
    for (int i = 1; i < n; ++i) { 
        for (int j = 500; j <= 30500; ++j) { 
            d[i][j] = d[i - 1][j] || d[i - 1][j - w[i]] || d[i - 1][j + w[i]];
        }
    }
    
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> t;
        if (t > 15000) {
            cout << "N ";
            continue;
        }
        
        cout << (d[n - 1][15500 + t] ? "Y " : "N ");
    }
}
