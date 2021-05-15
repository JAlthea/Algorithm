#include <bits/stdc++.h>

int main()
{
	long long n, m;
	scanf("%lld%lld", &n, &m);
	std::vector<long long> v(n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", &v[i]);

	long long max, min, mid, result;
	max = *std::max_element(v.begin(), v.end());
	min = 0;
	result = 0;

	while (min <= max)
	{
		mid = (max + min) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; ++i)
			if (v[i] - mid > 0)
				tmp += v[i] - mid;

		if (tmp >= m)
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
