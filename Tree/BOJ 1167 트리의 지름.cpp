#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> edge;
vector<bool> visited;
int e, maxLength;

void dfs(int v, int length)
{
	visited[v] = true;
	
	if (maxLength < length)
	{
		maxLength = length;
		e = v;
	}

	for (int i = 0; i < edge[v].size(); ++i)
	{
		int next = edge[v][i].first;
		int weight = edge[v][i].second;
		if (visited[next] == false)
			dfs(next, length + weight);
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, from, to = 0, distance;
	cin >> n;
	edge.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < n; ++i)
	{
		cin >> from;
		while (1)
		{
			cin >> to;
			if (to == -1) break;
			cin >> distance;
			edge[from].push_back({ to, distance });
			edge[to].push_back({ from, distance });
		}
	}

	dfs(1, 0);
	maxLength = 0; visited.clear(); visited.resize(n + 1);
	dfs(e, 0);
	cout << maxLength;
}
