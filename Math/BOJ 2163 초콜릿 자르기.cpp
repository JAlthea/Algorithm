#include <ios>
int n, m, d[301][301];
int main()
{
	scanf("%d%d", &n, &m);
	d[2][1] = 1;
	d[1][2] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (i == 1 && j == 1) continue;
			else if (i == 1) d[1][j] = j - 1;
			else if (j == 1) d[i][1] = i - 1;
			else d[i][j] = d[i - 1][j] + d[1][j] + 1;
		}
	}
	printf("%d", d[n][m]);
}
