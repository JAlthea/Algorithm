#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

map<int, int> bfs(vector<vector<char>> &board, vector<vector<int>> &home)
{
	int dy[] = { -1, 1, 0, 0 };
	int dx[] = { 0, 0, -1, 1 };
	int n = board.size();
	vector<vector<int>> check(n, vector<int>(n, 0));
	map<int, int> m;
	for (int i = 0; i < home.size(); i++)
	{
		int y = home[i][0];
		int x = home[i][1];
		if (check[y][x])
			continue;

		queue<vector<int>> q;
		q.push({ y, x, i + 1 });    //Color = 1, 2, ...
		m.insert({ i + 1, 0 });
		while (!q.empty())
		{
			vector<int> v = q.front(); q.pop();
			y = v[0];
			x = v[1];
			int id = v[2];

			if (check[y][x])
				continue;
			check[y][x] = id;    //Coloring
			m[id]++;

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;

				if (board[ny][nx] == '1')
					q.push({ ny, nx, id });    //Same Coloring
			}
		}
	}

	return m;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<char>> board(n, vector<char>(n, 0));
	vector<vector<int>> home;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == '1')
				home.push_back({ i, j, 0 });
		}
	}

	map<int, int> m = bfs(board, home);
	vector<pair<int, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	cout << v.size() << "\n";
	for (auto i : v)
		cout << i.second << " ";
}
