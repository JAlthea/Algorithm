#import <bits/stdc++.h>
int n, i, j, t, d[100001];
int main()
{
	scanf("%d", &n);
	for (i = 1; d[i] = 5, i <= n; ++i)
		for (j = (int)sqrt(i); j > 0; --j)
			t = 1 + d[i - j * j], d[i] > t ? d[i] = t : 0;
	printf("%d", d[n]);
}
