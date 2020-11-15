#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b, x, y;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<vector<int>> pSum(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			pSum[i][j] = arr[i - 1][j - 1] + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];

	while (m--)
	{
		cin >> a >> b >> x >> y;
		cout << pSum[x][y] - pSum[x][b - 1] - pSum[a - 1][y] + pSum[a - 1][b - 1] << '\n';
	}
}
