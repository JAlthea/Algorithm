#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, from, to;
	cin >> n;
	vector<vector<int>> edge(n + 1);
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> from >> to;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	vector<int> parent(n + 1, 0);
	parent[1] = -1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int nowParent = q.front(); q.pop();

		for (int i = 0; i < edge[nowParent].size(); ++i)
		{
			int child = edge[nowParent][i];
			if (parent[child] == 0)
			{
				parent[child] = nowParent;
				q.push(child);
			}
		}
	}

	for (int i = 2; i <= n; ++i)
		cout << parent[i] << ' ';
}
