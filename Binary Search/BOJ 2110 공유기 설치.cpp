#include <bits/stdc++.h>

int main()
{
	long long n, c, max, min, mid, result;
	scanf("%lld%lld", &n, &c);
	std::vector<long long> v(n);
	for (int i = 0; i < n; ++i)
	    scanf("%lld", &v[i]);
        std::sort(v.begin(), v.end());
    
	max = v[n - 1];
	min = 1;
	result = 0;
	while (min <= max)
	{
		mid = (max + min) / 2;

		long long now = v[0];
		int count = 0;
		for (int i = 1; i < n; ++i)
		{
			if (count == c - 1)
				break;
			if (v[i] - now >= mid)
			{
				count++;
				now = v[i];
			}
		}

		if (count == c - 1)
		{
			if (result < mid)
				result = mid;
			min = mid + 1;
		}
		else
			max = mid - 1;
	}

	printf("%lld", result);
}
