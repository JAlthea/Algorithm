#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> & edge, int n, int from) {
    int ret = 1;
    vector<vector<bool>> check(n + 1, vector<bool>(n + 1));
    
    queue<int> q;
    q.push(from);
    while (!q.empty()) {
        int now = q.front(); q.pop();
        
        for (int i = 0; i < edge[now].size(); ++i) {
            int to = edge[now][i];
            if (to == -1 || check[now][to])
                continue;
            
            check[now][to] = true;
            check[to][now] = true;
            q.push(to);
            ++ret;
        }
    }

    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> edge(n + 1);
    
    for (int i = 0; i < wires.size(); ++i) {
        int from = wires[i][0];
        int to = wires[i][1];
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    for (int from = 1; from <= n; ++from) {
        for (int i = 0; i < edge[from].size(); ++i) {
            int to = edge[from][i];
            edge[from][i] = -1;
            
            for (int j = 0; j < edge[to].size(); ++j) {
                if (edge[to][j] == from) {
                    edge[to][j] = -1;
                    int onePartCount = abs(n - bfs(edge, n, 1));
                    int otherPartCount = bfs(edge, n, 1);
                    answer = min(answer, abs(onePartCount - otherPartCount));
                    edge[to][j] = from;
                    break;
                }
            }
            
            edge[from][i] = to;
        }
    }
    
    return answer;
}
