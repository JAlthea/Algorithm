#include <bits/stdc++.h>
using namespace std;

int n, m, start;
void dfs(vector<vector<int>> &v, int start)
{
	vector<bool> visited(n + 1, false);
	stack<int> s;
	s.push(start);
	while (!s.empty())
	{
		int now = s.top();
		s.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		printf("%d ", now);

		for (int i = n; i > 0; --i)
			if (v[now][i])
				s.push(i);
	}
}

void bfs(vector<vector<int>> &v, int start)
{
	vector<bool> visited(n + 1, false);
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (visited[now])
			continue;
		visited[now] = true;
		printf("%d ", now);

		for (int i = 1; i <= n; ++i)
			if (v[now][i])
				q.push(i);
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &start);
	vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		v[a][b]++;
		v[b][a]++;
	}
	dfs(v, start);
	puts("");
	bfs(v, start);
}
