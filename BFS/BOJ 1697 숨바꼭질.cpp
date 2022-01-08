#include <bits/stdc++.h>
using namespace std;

int main() {
    int check[100001] = { 0 };
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> q;
    q.push({ 0, n });

    while (!q.empty()) {
        pair<int, int> p = q.front(); q.pop();

        if (p.second == k) {
            cout << p.first;
            return 0;
        }

        if (check[p.second])
            continue;
        ++check[p.second];

        int nx[] = { p.second + 1, p.second - 1, p.second * 2 };

        for (int i = 0; i < 3; ++i)
            if (nx[i] >= 0 && nx[i] <= 100000)
                q.push({ p.first + 1, nx[i] });
    }
}