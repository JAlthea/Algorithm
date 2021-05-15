#include <bits/stdc++.h>
using namespace std;

int n, d[1001][3], s[3];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 3; i++)
		scanf("%d", &d[0][i]);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
			scanf("%d", &s[j]);
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + s[0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + s[1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + s[2];
	}
	printf("%d", min(d[n - 1][0], min(d[n - 1][1], d[n - 1][2])));
}
