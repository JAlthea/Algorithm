#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	queue<pair<int, int>> q;
	q.push({ 0, n });
	int check[100001] = { 0 };
	int fastestTime = -1;
	int count = 0;
	while (!q.empty())
	{
		pair<int, int> p = q.front(); q.pop();

		if (p.second == k)
		{
			if (fastestTime == -1)
				fastestTime = p.first;
			if (fastestTime == p.first)
				count++;
		}
        
		check[p.second]++;

		int nx[] = { p.second + 1, p.second - 1, p.second * 2 };
		for (int i = 0; i < 3; i++)
			if (nx[i] >= 0 && nx[i] <= 100000 && check[nx[i]] == 0)
				q.push({ p.first + 1, nx[i] });
	}
	cout << fastestTime << '\n' << count;
}
