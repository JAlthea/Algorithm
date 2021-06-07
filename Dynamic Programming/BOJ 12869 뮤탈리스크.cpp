#include <bits/stdc++.h>
using namespace std;

int a[61][61][61];

int f(int h1, int h2, int h3) {
    if (h1 < 0) h1 = 0;
    if (h2 < 0) h2 = 0;
    if (h3 < 0) h3 = 0;
    
    if (h1 == 0 && h2 == 0 && h3 == 0)
        return 0;

    if (a[h1][h2][h3] != -1)
        return a[h1][h2][h3];
    
    int ret = INT_MAX;
    ret = min(f(h1 - 9, h2 - 3, h3 - 1) + 1, ret);
    ret = min(f(h1 - 9, h2 - 1, h3 - 3) + 1, ret);
    ret = min(f(h1 - 3, h2 - 1, h3 - 9) + 1, ret);
    ret = min(f(h1 - 3, h2 - 9, h3 - 1) + 1, ret);
    ret = min(f(h1 - 1, h2 - 9, h3 - 3) + 1, ret);
    ret = min(f(h1 - 1, h2 - 3, h3 - 9) + 1, ret);
    return a[h1][h2][h3] = ret;
}

int main() {
    int n;
    cin >> n;
    vector<int> scv(3, 0);
    for (int i = 0; i < n; ++i) {
        cin >> scv[i];
    }
    
    memset(a, -1, sizeof(a));
    cout << f(scv[0], scv[1], scv[2]);
}
