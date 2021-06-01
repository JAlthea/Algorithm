#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int tc, n, m, w, s, e, t;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		vector<long long> dist(n + 1, INT_MAX);
		vector<vector<pair<long long, long long>>> edge(n + 1);
		for (int i = 0; i < m; ++i) {
			cin >> s >> e >> t;
			edge[s].push_back({ e, t });
			edge[e].push_back({ s, t });
		}
		for (int i = 0; i < w; ++i) {
			cin >> s >> e >> t;
			edge[s].push_back({ e, -t });
		}

		bool isPossible = false;
		for (int i = 0; i < n; ++i) {
			for (int from = 1; from <= n; ++from) {
				for (int j = 0; j < edge[from].size(); ++j) {
					int to = edge[from][j].first;
					int cost = edge[from][j].second;
                
						if (dist[to] > dist[from] + cost) {
							dist[to] = dist[from] + cost;
							if (i == n - 1)
								isPossible = true;
						}
					}
				}
			}
        
			cout << (isPossible ? "YES\n" : "NO\n");
		}
}
