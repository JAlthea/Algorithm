#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> edge;
vector<bool> visited;
int maxLength, e;

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
	ios::sync_with_stdio(0); cin.tie(0);
	int n, start, end, weight;
	cin >> n;
	edge.resize(n + 1);
	visited.resize(n + 1);
	maxLength = 0, e = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		cin >> start >> end >> weight;
		edge[start].push_back({ end, weight });
		edge[end].push_back({ start, weight });
	}

	dfs(1, 0);
	maxLength = 0; visited.clear(); visited.resize(n + 1);
	dfs(e, 0);
	cout << maxLength;
}
