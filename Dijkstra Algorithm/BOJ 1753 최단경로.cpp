#include <ios>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, m, start;
	scanf("%d%d%d", &n, &m, &start);
	vector<vector<pair<int, int>>> v(n + 1);
	
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({ b, c });
	}
	vector<int> dist(n + 1, 999999);

	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	
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

	for (int i = 1; i <= n; ++i)
		if (dist[i] == 999999)
			puts("INF");
		else
			printf("%d\n", dist[i]);
}
