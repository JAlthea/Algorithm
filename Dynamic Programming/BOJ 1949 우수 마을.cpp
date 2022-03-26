#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
int c[10001], d[10001][2];

void makeTree(int node, int parent) {
    d[node][0] = 0;
    d[node][1] = c[node];
    
    for (int i = 0; i < edge[node].size(); ++i) {
        if (edge[node][i] == parent) {
            continue;
        }
        
        makeTree(edge[node][i], node);
        
        d[node][0] += max(d[edge[node][i]][0], d[edge[node][i]][1]);
        d[node][1] += d[edge[node][i]][0];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t1, t2;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    
    edge.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    
    makeTree(1, -1);
    
    cout << max(d[1][0], d[1][1]);
}
