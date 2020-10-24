#include <bits/stdc++.h>
using namespace std;

int minCost, startIndex;

void TSP(vector<vector<int>> &m, vector<bool> &checked, int from, int cost, int count)
{
	if (count == checked.size() && m[from][startIndex] != 0)
	{
		minCost = min(minCost, cost + m[from][startIndex]);
		return;
	}

	for (int to = 0; to < checked.size(); ++to)
	{
		if (checked[to] || m[from][to] == 0) continue;
		checked[to] = true;
		TSP(m, checked, to, cost + m[from][to], count + 1);
		checked[to] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> m(n, vector<int>(n, 0));
	vector<bool> checked(n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> m[i][j];

	minCost = INT_MAX;
	startIndex = 0;
	checked[startIndex] = true;
	TSP(m, checked, 0, 0, 1);
	cout << minCost;
}
