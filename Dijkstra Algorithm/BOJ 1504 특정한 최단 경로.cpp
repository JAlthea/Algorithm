#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x, y;
	scanf("%d%d", &n, &m);
	vector<vector<pair<int, int>>> v(2 * n + 1);
	
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b, c });
		v[b].push_back({ a, c });
	}
	scanf("%d%d", &x, &y);

	int s[2] = { 0 };
	for (int k = 0; k < 2; ++k) {
		vector<int> d;
		if (k == 0)
			d = { 1, x, y, n };
		else
			d = { 1, y, x, n };

		for (int i = 0; i < 3; ++i) {
			vector<int> dist(n + 1, 999999);
			priority_queue<pair<int, int>> pq;
			pq.push({ 0, d[i] });
			dist[d[i]] = 0;

			while (!pq.empty()) {
				int cost = -1 * pq.top().first;
				int here = pq.top().second;
				pq.pop();

				for (int i = 0; i < v[here].size(); ++i) {
					int next = v[here][i].first;
					int nextCost = v[here][i].second;

					if (dist[next] > dist[here] + nextCost) {
						dist[next] = dist[here] + nextCost;
						pq.push({ -1 * dist[next], next });
					}
				}
			}

			s[k] += dist[d[i + 1]];
		}
	}

	if (s[0] >= 999999 && s[1] >= 999999)
		puts("-1");
	else
		printf("%d\n", s[0] < s[1] ? s[0] : s[1]);
}
