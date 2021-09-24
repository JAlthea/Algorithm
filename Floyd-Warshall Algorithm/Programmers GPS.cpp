#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> edge(n + 1);
    vector<vector<int>> dist(k, vector<int>(n + 1, 1e9));
    for (int i = 0; i < m; ++i) {
        int from = edge_list[i][0];
        int to = edge_list[i][1];
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    dist[0][gps_log[0]] = 0;    //처음 시작 위치는 고정
    for (int i = 1; i < k; ++i) {
        for (int to = 1; to <= n; ++to) {
            dist[i][to] = min(dist[i][to], dist[i - 1][to]);
            
            for (int from : edge[to])
                dist[i][to] = min(dist[i][to], dist[i - 1][from]);
            
            dist[i][to] += (gps_log[i] == to ? 0 : 1);
        }
    }
    
    return dist[k - 1][gps_log[k - 1]] >= 1e9 ? -1 : dist[k - 1][gps_log[k - 1]];
}
