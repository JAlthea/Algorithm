#include <bits/stdc++.h>
using namespace std;

struct info {
	int delay, cost, to;
	bool operator<(const info &ip) const {
		return delay > ip.delay;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	
	while (t--) {
		int n, m, k, from, to, cost, delay;
		cin >> n >> m >> k;
		vector<vector<info>> edge(n + 1);    // from = { to, cost, delay }
		vector<vector<int>> delays(n + 1, vector<int>(m + 1, INT_MAX));    // all delays by edge
		
		for (int i = 0; i < k; ++i) {
			cin >> from >> to >> cost >> delay;
			edge[from].push_back({ delay, cost, to });
		}

		delays[1][0] = 0;
		priority_queue<info> q;
		q.push({ 0, 0, 1 });
		
		while (!q.empty()) {
			info ip = q.top(); q.pop();
			int now = ip.to;
			int nowDelay = ip.delay;
			int nowCost = ip.cost;
			
			if (delays[now][nowCost] < nowDelay)
				continue;
			delays[now][nowCost] = nowDelay;

			for (int i = 0; i < edge[now].size(); ++i) {
				int next = edge[now][i].to;
				int nextCost = edge[now][i].cost;
				int nextDelay = edge[now][i].delay;
				if (nowCost + nextCost > m)
					continue;
                
				if (delays[next][nowCost + nextCost] > nowDelay + nextDelay) {
					for (int i = nowCost + nextCost; i <= m; ++i)
   					    if (delays[next][i] > nowDelay + nextDelay)
					        delays[next][i] = nowDelay + nextDelay;
					q.push({ nowDelay + nextDelay, nowCost + nextCost, next });
				}
			}
		}

		int minDelay = INT_MAX;
		for (int i = 0; i <= m; ++i)
			minDelay = min(minDelay, delays[n][i]);

		cout << minDelay == INT_MAX ? "Poor KCM\n" : '\n';
	}
}
