#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, from, to;
	cin >> n >> m;
	vector<int> result;
	vector<vector<int>> edge(n + 1);
	vector<int> indegree(n + 1, 0);
	queue<int> q;
	for (int i = 0; i < m; ++i)
	{
		cin >> from >> to;
		edge[from].push_back(to);
		indegree[to]++;
	}
    
	for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0) q.push(i);
    
	while (!q.empty())
	{
		int now = q.front(); q.pop();
		result.push_back(now);
		indegree[now] = -1;
		for (int i = 0; i < edge[now].size(); ++i)
		{
			int next = edge[now][i];
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}

	for (int i = 0; i < result.size(); ++i) cout << result[i] << ' ';
}
