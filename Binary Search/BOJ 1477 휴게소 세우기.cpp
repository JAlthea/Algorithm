#include <bits/stdc++.h>

int main()
{
	int n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	v.push_back(0);
	v.push_back(l);
	std::sort(v.begin(), v.end());

	int max, min, mid, result;
	max = l;
	min = 0;
	result = l;
	while (min <= max) 
	{
		mid = (min + max) / 2;
		
		int count = 0;
		for (int i = 1; i < v.size(); ++i)
			count += (v[i] - v[i - 1] - 1) / mid;

		if (count > m)
			min = mid + 1;
		else
		{
			if (result > mid)
				result = mid;
			max = mid - 1;
		}
	}

	printf("%d", result);
}
