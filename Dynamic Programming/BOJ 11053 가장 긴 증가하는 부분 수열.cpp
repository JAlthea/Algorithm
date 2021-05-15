#include <bits/stdc++.h>
int main()
{
	int n, d[1001] = { 0 }, s[1001] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &d[i]);

	for (int i = 1; i <= n; i++)
	{
		int now = d[i];
		int maxCount = 0;
		for (int j = 1; j < i; j++)
			if (d[i] > d[j])
				maxCount = std::max(maxCount, s[j]);
		s[i] = maxCount + 1;
	}
	printf("%d", *std::max_element(s, s + n + 1));
}
