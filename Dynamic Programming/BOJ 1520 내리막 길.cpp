#include <bits/stdc++.h>
using namespace std;

int m, n, d[501][501], check[501][501], l;
const int dy[] = { 0, 0, 1, -1 };
const int dx[] = { 1, -1, 0, 0 };

int main()
{
	cin >> m >> n;
	vector<vector<int>> c(m * n, vector<int>(3, 0));
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
			c[l][0] = d[i][j];
			c[l][1] = i;
			c[l][2] = j;
			l++;
		}
	}
	sort(c.begin(), c.end(), greater<vector<int>>());

	check[1][1] = 1;
	for (int i = 0; i < m * n; i++)
	{
		int weight = c[i][0];
		int y = c[i][1];
		int x = c[i][2];

		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny > m || nx > n)
				continue;

			if (check[y][x] == 0)
				continue;

			if (weight > d[ny][nx])
				check[ny][nx] += check[y][x];
		}
	}

	cout << check[m][n];
}
