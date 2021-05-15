#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin.ignore();
	vector<vector<char>> board(n, vector<char>(m, '0'));
	vector<vector<vector<bool>>> checkedBoard(2, vector<vector<bool>>(n, vector<bool>(m, false)));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	queue<vector<int>> q;    //{ y, x, distance, isPower }
	q.push({ 0, 0, 1, 1 });
	while (!q.empty())
	{
		vector<int> v = q.front(); q.pop();
		int y = v[0];
		int x = v[1];
		int nowDistance = v[2];
		int isPower = v[3];

		if (y == n - 1 && x == m - 1)
		{
			cout << nowDistance;
			return 0;
		}

		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nIsPower = isPower;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (checkedBoard[nIsPower][ny][nx])
				continue;

			if (board[ny][nx] == '1')
			{
				if (nIsPower == 1)
					nIsPower = 0;
				else
					continue;
			}

			checkedBoard[nIsPower][ny][nx] = true;
			q.push({ ny, nx, nowDistance + 1, nIsPower });
		}
	}

	cout << -1;
}
