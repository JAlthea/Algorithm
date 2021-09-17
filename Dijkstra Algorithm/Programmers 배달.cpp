#include <vector>
#include <queue>
using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<pair<int, int>> v[2 * N + 1];
    for (int i = 0; i < road.size(); ++i) {
        v[road[i][0]].push_back(make_pair(road[i][1], road[i][2]));
        v[road[i][1]].push_back(make_pair(road[i][0], road[i][2]));
    }
    vector<int> dist(N + 1, 999999);
    
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

    for (int i = 1; i <= N; ++i)
        if (dist[i] <= K)
            ++answer;
    
    return answer;
}
