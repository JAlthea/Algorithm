#include <iostream>
#include <vector>
using namespace std;

int div(int n) { return n > 999 ? n %= 1000 : n; }

vector<vector<int>> matrixMultiple(vector<vector<int>> &a, vector<vector<int>> &b)
{
	int n = a.size();
	int m = b[0].size();
	vector<vector<int>> c(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < n; ++k)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] = div(c[i][j]);
		}
	}
	return c;
}

vector<vector<int>> expo(vector<vector<int>> &v, long long b)
{
	if (b == 1)
		return v;

	vector<vector<int>> tmp;
	if (b % 2 == 0)
	{
		tmp = expo(v, b / 2);
		return matrixMultiple(tmp, tmp);
	}
	else
	{
		tmp = expo(v, b - 1);
		return matrixMultiple(v, tmp);
	}
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(0);
    int n;
    long long b;
    cin >> n >> b;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            cin >> v[i][j];
    v = expo(v, b);
    for (int i=0; i<n; cout << "\n", ++i)
        for (int j=0; j<n; ++j)
            cout << div(v[i][j]) << ' ';
}
