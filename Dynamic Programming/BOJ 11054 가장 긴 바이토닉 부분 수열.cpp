#include <bits/stdc++.h>

int main()
{
	int n, a[1001] = { 0 }, d[1001][3] = { { 0 } };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)	//left -> right
	{
		int now = a[i];
		int maxCount = 0;
		for (int j = 1; j < i; j++)
			if (a[i] > a[j])
				maxCount = std::max(maxCount, d[j][0]);
		d[i][0] = maxCount + 1;
	}
	for (int i = n; i >= 1; i--)	//right -> left
	{
		int now = a[i];
		int maxCount = 0;
		for (int j = n; j > i; j--)
			if (a[i] > a[j])
				maxCount = std::max(maxCount, d[j][1]);
		d[i][1] = maxCount + 1;
	}

	int maxSeq = 0;
	for (int i = 1; i <= n; i++)	//left + right
		d[i][2] = d[i][0] + d[i][1] - 1, maxSeq = std::max(maxSeq, d[i][2]);
	printf("%d", maxSeq);
}
