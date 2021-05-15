#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> d(1 << 25);
    while (!cin.eof()) {
        int t;
        cin >> t;
        if (!d[t]) 
          cout << t << ' ';
        d[t] = true;
    }
}
