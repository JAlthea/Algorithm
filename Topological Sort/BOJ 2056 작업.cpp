#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, taskCount;
	cin >> n;
	vector<int> costTimes(n + 1);
	vector<int> accumCostTimes(n + 1, 0);
	vector<vector<int>> edge(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> costTimes[i] >> taskCount;
		int end = i;
		int start;
		for (int j = 0; j < taskCount; ++j)
		{
			cin >> start;
			edge[start].push_back(end);
		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < edge[i].size(); ++j)
		{
			int now = i;
			int next = edge[i][j];
			accumCostTimes[next] = max(accumCostTimes[next], costTimes[now] + accumCostTimes[now]);
		}
	}
    
	int maxCost = 0;
	for (int i = 1; i <= n; ++i)
		maxCost = max(maxCost, accumCostTimes[i] + costTimes[i]);

	cout << maxCost;
}
