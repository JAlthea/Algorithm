#include <bits/stdc++.h>
using namespace std;

vector<int> sets, h;

int findSet(int e) {
    if (sets[e] == e) 
        return e;
    return sets[e] = findSet(sets[e]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    
    if (a == b) 
        return;
    
    if (h[a] < h[b]) 
        sets[a] = b;
    else 
        sets[b] = a;
    
    if (h[a] == h[b]) 
        h[a]++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, op, from, to;
    cin >> n >> m;
    sets.resize(n + 1);
    h.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        sets[i] = i;
        h[i] = 1;
    }
    
    for (int i = 0; i < m; ++i) {
        cin >> op >> from >> to;
        if (op == 0) {
            unionSet(from, to);
            continue;
        }
        
        cout << (findSet(from) == findSet(to) ? "YES\n" : "NO\n");
    }
}
