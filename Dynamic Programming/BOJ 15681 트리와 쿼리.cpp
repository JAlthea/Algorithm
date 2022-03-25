#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> tree;
int d[100001];

int makeTree(int node, int parent) {
    d[node] = 1;
    
    for (int i = 0; i < tree[node].size(); ++i) {
        if (tree[node][i] == parent) {
            continue;
        }
        
        d[node] += makeTree(tree[node][i], node);
    }
    
    return d[node];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, q, t1, t2;
    cin >> n >> r >> q;
    tree.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> t1 >> t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    
    makeTree(r, -1);
    
    for (int i = 0; i < q; ++i) {
        cin >> t1;
        cout << d[t1] << '\n';
    }
}
