#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, j, x = 1, ret = 0, t, l, r;
    cin >> n >> m >> j;
    while (j--) {
        cin >> t;
        if (x + m - 1 < t || t < x) {
            l = x;
            r = x + m - 1;
            if (l - t > t - r) {
                ret += l - t;
                x -= l - t;
            }
            else {
                ret += t - r;
                x += t - r;
            }
        }
    }
    cout << ret;
}
