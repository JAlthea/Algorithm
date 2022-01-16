#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, s, t;
    cin >> n >> m;

    vector<bool> b(n + 1);
    vector<int> d[1000000];
    for (int i = 0; i < m; ++i) {
        cin >> s >> t;
        d[s].push_back(t);
        d[t].push_back(s);
    }
    
    int ret = 0;
    for (int s = 1; s <= n; ++s) {
        if (b[s])
            continue;
        b[s] = true;

        queue<int> q;
        q.push(s);
        
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = 0; i < d[now].size(); ++i) {
                int e = d[now][i];

                if (b[e])
                    continue;
                b[e] = true;

                q.push(e);
            }
        }
        
        ++ret;
    }
    
    cout << ret;
}