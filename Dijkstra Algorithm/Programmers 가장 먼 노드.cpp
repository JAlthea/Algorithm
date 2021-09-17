#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge)  {
    int answer = 0;
    vector<pair<int, int>> v[n + 1];
    for (int i = 0; i < edge.size(); ++i) {
        v[edge[i][0]].push_back(make_pair(edge[i][1], 1));
        v[edge[i][1]].push_back(make_pair(edge[i][0], 1));
    }
    vector<int> dist(n + 1, 999999);
    
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));
    dist[1] = 0;
    while (!pq.empty()) {
        int cost = -1 * pq.top().first;
        int here = pq.top().second;
        pq.pop();
 
        for (int i = 0; i < v[here].size(); ++i) {
            int next = v[here][i].first;
            int nextCost = v[here][i].second;
            
            if (dist[next] > dist[here] + nextCost) {
                dist[next] = dist[here] + nextCost;
                pq.push(make_pair(-1 * dist[next], next));
            }
        }
    }

    sort(dist.begin(), dist.end(), greater<int>());
    int max = dist[1];
    for (int i = 1; i <= n; ++i) {
        if (max == dist[i])
            answer++;
        else
            break;
    }
    
    return answer;
}
