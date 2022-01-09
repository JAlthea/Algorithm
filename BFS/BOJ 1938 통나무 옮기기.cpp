#include <bits/stdc++.h>
using namespace std;

const int VERTICAL = 0;
const int HORIZENTAL = 1;
const int dy[2][4] = {{ 0, 0, 2, -2 }, { 1, -1, 0 ,0 }};    //4방향
const int dx[2][4] = {{ 1, -1, 0 ,0 }, { 0, 0, 2, -2 }};
const int ty[2][4] = {{ -1, -1, 0, 0}, { 1, -1, 0, 0}};    //대각선 위
const int tx[2][4] = {{ 1, -1, 0, 0}, { -1, -1, 0, 0}};
const int by[2][4] = {{ 1, 1, 0, 0}, { 1, -1, 0, 0}};    //대각선 아래
const int bx[2][4] = {{ 1, -1, 0, 0}, { 1, 1, 0, 0}};
const int ry[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 };    //회전
const int rx[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	vector<vector<char>> board(n, vector<char>(n));
	vector<vector<int>> B, E;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 'B')
				B.push_back({ i, j });
			else if (board[i][j] == 'E')
				E.push_back({ i, j });
		}
	}
	
	int direction = VERTICAL;
	if (B[0][0] == B[1][0])
		direction = HORIZENTAL;
	vector<int> bInfo = { 0, B[1][0], B[1][1], direction };

	if (E[0][0] == E[1][0])
		direction = HORIZENTAL;
	else
		direction = VERTICAL;
	vector<int> EInfo = { E[1][0], E[1][1], direction };

	set<vector<int>> check;
	queue<vector<int>> q;
	q.push(bInfo);

	while (!q.empty()) {
		vector<int> v = q.front(); q.pop();
		int count = v[0];
		int y = v[1];
		int x = v[2];
		int d = v[3];
		int goalY = EInfo[0];
		int goalX = EInfo[1];
		int goalD = EInfo[2];

		if (y == goalY && x == goalX && d == goalD) {
			cout << count;
			return 0;
		}

		if (check.find({ y, x, d }) != check.end())
			continue;
		check.insert({ y, x, d });

		//Move
		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[d][i];
			int nx = x + dx[d][i];
			int nty = y + ty[d][i];
			int ntx = x + tx[d][i];
			int nby = y + by[d][i];
			int nbx = x + bx[d][i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (nty < 0 || ntx < 0 || nty >= n || ntx >= n)
				continue;

			if (nby < 0 || nbx < 0 || nby >= n || nbx >= n)
				continue;

			if (board[ny][nx] == '1' || board[nty][ntx] == '1' || board[nby][nbx] == '1')
				continue;

			if (i >= 2) {
				ny = y + (dy[d][i] / 2);
				nx = x + (dx[d][i] / 2);
			}
				
			q.push({count + 1, ny, nx, d});
		}

		//Rotate
		bool isRotated = true;
		for (int i = 0; i < 9; ++i) {
			int nry = y + ry[i];
			int nrx = x + rx[i];

			if (nry < 0 || nrx < 0 || nry >= n || nrx >= n) {
				isRotated = false;
				break;
			}

			if (board[nry][nrx] == '1') {
				isRotated = false;
				break;
			}
		}

		if (isRotated)
			q.push({ count + 1, y, x, (d + 1) % 2 });
	}

	cout << 0;
}
