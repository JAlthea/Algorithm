#include <bits/stdc++.h>
using namespace std;

vector<int> s, h;

int findSet(int e) {
    if (s[e] == e) 
        return e;
    return s[e] = findSet(s[e]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a == b) 
        return;
    
    if (h[a] < h[b]) 
        s[a] = b;
    else 
        s[b] = a;
    
    if (h[a] == h[b]) 
       ++h[a];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, op;
    cin >> n >> m;
    vector<int> path(m, 0);
    s.resize(n + 1);
    h.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        s[i] = i;
        h[i] = 1;
    }
    
    for (int from = 1; from <= n; ++from) {
        for (int to = 1; to <= n; ++to) {
            cin >> op;
            
            if (from == to) 
                continue;
            
            if (op == 1) 
                unionSet(from, to);
        }
    }
    
    cin >> path[0];
    int root = findSet(path[0]);
    bool isPossible = true;
    
    for (int i = 1; i < m; ++i) {
        cin >> path[i];
        
        if (root != findSet(path[i])) {
            isPossible = false;
            break;
        }
    }

    cout << (isPossible ? "YES" : "NO");
}
