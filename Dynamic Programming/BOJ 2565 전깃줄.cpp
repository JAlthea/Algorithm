#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<vector<int>> d(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++)
		scanf("%d%d", &d[i][0], &d[i][1]);
	sort(d.begin(), d.end());

	int maxCount = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			if (d[i][1] > d[j][1])
				d[i][2] = max(d[i][2], d[j][2]);
		d[i][2]++;
		maxCount = max(maxCount, d[i][2]);
	}
	printf("%d", n - maxCount);
}
