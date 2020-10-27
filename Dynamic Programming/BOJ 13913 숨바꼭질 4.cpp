#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	int count = 0;
	queue<pair<int, int>> q;
	q.push({ 0, n });
	vector<int> check(100001, -1);
	while (!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();

		if (p.second == k)
		{
			count = p.first;
			break;
		}

		int nx[] = { p.second * 2, p.second + 1, p.second - 1 };
		for (int i = 0; i < 3; i++)
		{
			if (nx[i] >= 0 && nx[i] <= 100000 && check[nx[i]] == -1)
			{
				check[nx[i]] = p.second;
				q.push({ p.first + 1, nx[i] });
			}
		}
	}

	int pos = k;
	vector<int> backTrace;
	while (pos != n)
	{
		backTrace.push_back(pos);
		pos = check[pos];
	}

	cout << count << '\n' << n << ' ';
	for (int i = backTrace.size() - 1; i >= 0; i--)
		cout << backTrace[i] << ' ';
}
