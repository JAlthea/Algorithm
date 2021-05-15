#include <bits/stdc++.h>
using namespace std;

void convert3X3(vector<vector<char>> &a, int y, int x)
{
	for (int i = y - 1; i <= y + 1; ++i)
		for (int j = x - 1; j <= x + 1; ++j)
			a[i][j] = (a[i][j] == '0' ? '1' : '0');
}

bool isEqual(vector<vector<char>> &a, vector<vector<char>> &b)
{
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < a[0].size(); ++j)
			if (a[i][j] != b[i][j]) return false;
	return true;
}

bool isEqualBefore(vector<vector<char>> &a, vector<vector<char>> &b, int y, int x)
{
	if (a[y - 1][x - 1] != b[y - 1][x - 1]) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m; cin.ignore();

	vector<vector<char>> A(n, vector<char>(m)), B(n, vector<char>(m));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> A[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> B[i][j];

	if (isEqual(A, B))
	{
		cout << 0;
		return 0;
	}

	if (n < 3 || m < 3)
	{
		cout << -1;
		return 0;
	}

	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) continue;
			if (isEqualBefore(A, B, i, j)) continue;
			convert3X3(A, i, j);
			++ret;
		}
	}
	
	if (isEqual(A, B)) cout << ret;
	else cout << -1;
}
