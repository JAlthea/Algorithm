#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 0, -1, 1, -2, -2, -1, -1, 1, 1, 2, 2 };
const int dx[] = { 1, -1, 0, 0, -1, 1, -2, 2, -2, 2, -1, 1 };
int board[201][201];
int check[201][201][31];

inline int adjustPower(int power, int i) { return i > 3 ? power - 1 : power; }
int main()
{
	int k, w, h;
	scanf("%d %d %d", &k, &w, &h);
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			scanf("%d", &board[i][j]);

	queue<vector<int>> q;
	q.push({ 0, k, 0, 0 });
	check[0][0][k]++;
	while (!q.empty())
	{
		vector<int> v = q.front(); q.pop();
		int count = v[0];
		int power = v[1];
		int y = v[2];
		int x = v[3];

		if (y == h - 1 && x == w - 1)
		{
			cout << count;
			return 0;
		}

		for (int i = 0; i < 12; i++)
		{
			if (i > 3 && power == 0)
				continue;
            
			int ny = y + dy[i];
			int nx = x + dx[i];
			int np = adjustPower(power, i);
			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;

			if (board[ny][nx] || check[ny][nx][np])
				continue;
            
			check[ny][nx][np]++;
			q.push({ count + 1, np, ny, nx });
		}
	}

	cout << -1;
}
