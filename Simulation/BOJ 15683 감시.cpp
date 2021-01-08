#include <bits/stdc++.h>
using namespace std;

//Left:0, Top:1, Right:2, Bottom:3
const int DY[] = { 0, -1, 0, 1 };
const int DX[] = { -1, 0, 1, 0 };
const int MaxSize = 8;
int maxRet;

int countArea(vector<vector<pair<int, int>>> &b)
{
	int n = b.size();
	int m = b[0].size();
	int ret = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (b[i][j].first == -1) ++ret;
	return ret;
}

void _fill(vector<vector<pair<int, int>>> &b, int d, int y, int x)
{
	int n = b.size();
	int m = b[0].size();
	for (int i = 0; i < 4; ++i)
	{
		if (d != i) continue;

		int ny = y + DY[i];
		int nx = x + DX[i];
		while (ny >= 0 && nx >= 0 && ny < n && nx < m && b[ny][nx].first != 6)
		{
			if (b[ny][nx].first == 0) b[ny][nx].first = -1;
			ny += DY[i];
			nx += DX[i];
		}
	}
}

void uncheckArea(vector<vector<pair<int, int>>> &b)
{
	int n = b.size();
	int m = b[0].size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (b[i][j].first == -1) b[i][j].first = 0;
}

void checkArea(vector<vector<pair<int, int>>> &b)
{
	int n = b.size();
	int m = b[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			switch (b[i][j].first)
			{
			case 1:
				_fill(b, b[i][j].second, i, j);
				break;
			case 2:
				_fill(b, b[i][j].second, i, j);
				_fill(b, (b[i][j].second + 2) % 4, i, j);
				break;
			case 3:
				_fill(b, b[i][j].second, i, j);
				_fill(b, (b[i][j].second + 1) % 4, i, j);
				break;
			case 4:
				_fill(b, b[i][j].second, i, j);
				_fill(b, (b[i][j].second + 1) % 4, i, j);
				_fill(b, (b[i][j].second + 2) % 4, i, j);
				break;
			case 5:
				_fill(b, b[i][j].second, i, j);
				_fill(b, (b[i][j].second + 1) % 4, i, j);
				_fill(b, (b[i][j].second + 2) % 4, i, j);
				_fill(b, (b[i][j].second + 3) % 4, i, j);
				break;
			}
		}
	}
}

void simulation(vector<vector<pair<int, int>>> &b, int y, int x)
{
	int n = b.size();
	int m = b[0].size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (b[i][j].first < 1 || b[i][j].first > 5) continue;
			if (y * MaxSize + x > i * MaxSize + j) continue;

			for (int k = 0; k < 4; ++k)
			{
				checkArea(b);
				maxRet = max(maxRet, countArea(b));
				simulation(b, j == m - 1 ? i + 1 : i, j == m - 1 ? 0 : j + 1);
				uncheckArea(b);
				b[i][j].second = (b[i][j].second + 1) % 4;
			}
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, zeroCount = 0;
	cin >> n >> m;
	vector<vector<pair<int, int>>> board(n, vector<pair<int, int>>(m)); // { CCTV(0, 1~5, 6), Direction(0, 1, 2, 3) }
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j].first;
			if (board[i][j].first == 0) ++zeroCount;
			board[i][j].second = 0;
		}
	}

	simulation(board, 0, 0);
	cout << zeroCount - maxRet;
}
