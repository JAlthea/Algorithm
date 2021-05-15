#include <bits/stdc++.h>
using namespace std;

bool cmp(set<pair<int, int>> &a, set<pair<int, int>> &b)
{
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k, from, to, w;
		cin >> n >> k;
		vector<int> costTimes(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			cin >> costTimes[i];

		vector<int> accumCostTimes(n + 1, 0);

		vector<vector<int>> edge(n + 1);
		vector<int> indegree(n + 1, 0);
		for (int i = 0; i < k; ++i)
		{
			cin >> from >> to;
			edge[from].push_back(to);
			indegree[to]++;
		}

		cin >> w;

		for (int i = 1; i <= n; ++i)
		{
			int now, next;
			for (int j = 1; j <= n; ++j)
			{
				if (indegree[j] == 0)
				{
					now = j;
					break;
				}
			}
			
			indegree[now] = -1;
			for (int j = 0; j < edge[now].size(); ++j)
			{
				next = edge[now][j];
				accumCostTimes[next] = max(accumCostTimes[next], costTimes[now] + accumCostTimes[now]);
				indegree[next]--;
			}
		}

		cout << accumCostTimes[w] + costTimes[w] << '\n';
	}
}
