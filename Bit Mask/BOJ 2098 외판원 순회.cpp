#include <bits/stdc++.h>
using namespace std;

int n, cache[16][65536], dist[16][16];

int TSP(int from, int visited)
{
	if (visited == (1 << n) - 1 && dist[from][0]) return dist[from][0];
	int &ret = cache[from][visited];
	if (ret) return ret;
	ret = INT_MAX >> 1;
	for (int to = 0; to < n; ++to)
	{
		if (visited & (1 << to)) continue;
		if (dist[from][to] == 0) continue;
		ret = min(ret, TSP(to, visited | (1 << to)) + dist[from][to]);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	n = N;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> dist[i][j];
	cout << TSP(0, 1);
}
