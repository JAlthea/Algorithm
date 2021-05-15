#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, t, s, g, h;
		scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);
		vector<vector<pair<int, int>>> v(2 * n + 1);
		vector<int> ts(t);
		while (m--)
		{
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			v[a].push_back({ b, d });
			v[b].push_back({ a, d });
		}
		for (int i = 0; i < t; i++)
			scanf("%d", &ts[i]);
		
		sort(ts.begin(), ts.end());

		for (int q = 0; q < t; q++)
		{
			int tmp[3] = { 0 };
			for (int k = 0; k < 3; k++)
			{
				vector<int> d;
				if (k == 0)
					d = { s, g, h, ts[q] };
				else if (k == 1)
					d = { s, h, g, ts[q] };
				else
					d = { s, ts[q] };

				for (int i = 0; i < d.size() - 1; i++)
				{
					vector<int> dist(n + 1, 999999999);
					priority_queue<pair<int, int>> pq;
					pq.push({ 0, d[i] });
					dist[d[i]] = 0;

					while (!pq.empty())
					{
						int cost = -1 * pq.top().first;
						int here = pq.top().second;
						pq.pop();

						for (int i = 0; i < v[here].size(); i++)
						{
							int next = v[here][i].first;
							int nextCost = v[here][i].second;

							if (dist[next] > dist[here] + nextCost)
							{
								dist[next] = dist[here] + nextCost;
								pq.push({ -1 * dist[next], next });
							}
						}
					}

					tmp[k] += dist[d[i + 1]];
				}
			}

			int sum = min(tmp[0], tmp[1]);
			if (sum == tmp[2])
				printf("%d ", ts[q]);
		}

		puts("");
	}
}
