#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin.ignore();
	
	vector<vector<char>> board(n, vector<char>(m, '0'));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];

	vector<vector<bool>> checkedBoard(n, vector<bool>(m, false));
	queue<vector<int>> q;
	q.push({ 0, 0, 1 });

	while (!q.empty()) {
		vector<int> v = q.front(); q.pop();
		int y = v[0];
		int x = v[1];
		int nowCount = v[2];

		if (y == n - 1 && x == m - 1) {
			cout << nowCount;
			break;
		}

		for (int k = 0; k < 4; ++k) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (checkedBoard[ny][nx] || board[ny][nx] == '0')
				continue;

			checkedBoard[ny][nx] = true;
			q.push({ ny, nx, nowCount + 1 });
		}
	}
}