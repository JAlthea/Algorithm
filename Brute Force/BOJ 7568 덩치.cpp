#import <bits/stdc++.h>
using namespace std;

int n, d[51][2], c[51];
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &d[i][0], &d[i][1]);

	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			if (d[i][0] < d[j][0] && d[i][1] < d[j][1])
				count++;
		}
		c[i] = count + 1;
	}

	for (int i = 0; i < n; i++)
		printf("%d ", c[i]);
}
