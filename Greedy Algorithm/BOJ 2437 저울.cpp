#include <bits/stdc++.h>
using namespace std;

int d[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    
    sort(d, d + n);
    
    int ret = 1;
    for (int i = 0; i < n; ++i) {
        if (ret < d[i])
            break;
        ret += d[i];
    }
    
    cout << ret;
}
