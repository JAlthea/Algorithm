#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int v, e, a, b, c, d[401][401];
	cin >> v;
	for (int i = 1; i <= v; i++)
		for (int j = 1; j <= v; j++)
			d[i][j] = (i == j ? 0 : INT_MAX);

	cin >> e;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		d[a][b] = min(d[a][b], c);
	}

	for (int k = 1; k <= v; k++)
		for (int i = 1; i <= v; i++)
			for (int j = 1; j <= v; j++)
				if (d[i][k] != INT_MAX && d[k][j] != INT_MAX)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				
	int minCost = INT_MAX;
	for (int i = 1; i <= v; i++)
	{
		for (int j = 1; j <= v; j++)
		{
			if (i == j || d[i][j] == INT_MAX || d[j][i] == INT_MAX)
				continue;
			minCost = min(minCost, d[i][j] + d[j][i]);
		}
	}
    
	cout << (minCost == INT_MAX ? -1 : minCost);
}
