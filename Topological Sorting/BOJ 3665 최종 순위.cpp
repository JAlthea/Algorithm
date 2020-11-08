#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, from, to;
		vector<int> result;

		cin >> n;
		vector<int> pastRank(n + 1, 0);
		vector<vector<int>> edge(n + 1);
		vector<int> indegree(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			cin >> pastRank[i];

		vector<vector<bool>> info(n + 1, vector<bool>(n + 1, false));
		vector<vector<bool>> reverseInfo(n + 1, vector<bool>(n + 1, false));
		vector<bool> checkRank(n + 1, false);
		for (int i = 1; i <= n; ++i)	//작년 순위 정보로 가능한 모든 간선의 정보 연결
		{
			int from = pastRank[i];
			checkRank[from] = true;
			for (int to = 1; to <= n; ++to)
			{
				if (checkRank[to])
					continue;

				edge[from].push_back(to);
				indegree[to]++;
				info[from][to] = true;
			}
		}

		cin >> m;
		for (int i = 0; i < m; ++i)	//올해 바뀐 순위 정보를 간선으로 연결
		{
			int a, b;
			cin >> a >> b;
			if (info[a][b])
			{
				edge[b].push_back(a);
				indegree[a]++;
				reverseInfo[a][b] = true;
				indegree[b]--;
			}
			else
			{
				edge[a].push_back(b);
				indegree[b]++;
				reverseInfo[b][a] = true;
				indegree[a]--;
			}
		}

		queue<int> q;
		for (int i = 1; i <= n; ++i)
			if (indegree[i] == 0)
				q.push(i);

		while (!q.empty())
		{
			int now = q.front(); q.pop();
			result.push_back(now);
			indegree[now] = -1;
			for (int i = 0; i < edge[now].size(); ++i)
			{
				int next = edge[now][i];
				if (reverseInfo[now][next])
					continue;

				indegree[next]--;
				if (indegree[next] == 0)
					q.push(next);
			}
		}

		if (result.size() < n)
		{
			cout << "IMPOSSIBLE\n";
			continue;
		}
		
		for (int i = 0; i < n; ++i)
			cout << result[i] << ' ';
		cout << '\n';
	}
}
