#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<long long> dist(n + 1, LLONG_MAX);
	vector<vector<pair<int, int>>> edge(n + 1);

	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}

	dist[1] = 0;	//1번 도시 기준
	for (int i = 0; i < n; ++i) {
		for (int from = 1; from <= n; ++from) {
			for (int j = 0; j < edge[from].size(); ++j) {
				int to = edge[from][j].first;
				int cost = edge[from][j].second;

				if (dist[from] == LLONG_MAX)
					continue;
                
			    dist[to] = min(dist[to], dist[from] + cost);
			}
		}
	}

	for (int from = 1; from <= n; ++from) {
		for (int j = 0; j < edge[from].size(); ++j) {
			int to = edge[from][j].first;
			int cost = edge[from][j].second;

			if (dist[from] == LLONG_MAX)
				continue;

			if (dist[to] > dist[from] + cost) {
				cout << -1;
				return 0;
			}
		}
	}

	for (int i = 2; i <= n; ++i)
		cout << (dist[i] == LLONG_MAX ? -1 : dist[i]) << '\n';
}