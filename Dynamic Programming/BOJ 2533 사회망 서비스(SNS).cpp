#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edge;
bool d[1'000'001];

int makeTree(int node, int parent) {
    d[node] = false;
    
    int count = 0;
    for (int i = 0; i < edge[node].size(); ++i) {
        if (edge[node][i] == parent) {
            continue;
        }
        
        if (makeTree(edge[node][i], node) == 0) {
            ++count;
        }
    }
    
    if (count > 0) {
        d[node] = true;
    }
    
    return d[node];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t1, t2;
    cin >> n;
    
    edge.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i) {
        cin >> t1 >> t2;
        edge[t1].push_back(t2);
        edge[t2].push_back(t1);
    }
    
    makeTree(1, -1);
    
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (d[i]) {
            ++answer;
        }
    }
    
    cout << answer;
}
