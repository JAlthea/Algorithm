#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    
    map<string, int> h;
    string s;
    while (n--) {
        cin >> s;
        h[s] = 1;
    }
    
    int ret = 0;
    while (m--) {
        cin >> s;
        if (h[s] == 1) {
            ret++;
        }
    }
    
    cout << ret;
}
