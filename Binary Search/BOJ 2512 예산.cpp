#include <bits/stdc++.h>
using namespace std;

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	cin >> m;

	int min = 0, max = *max_element(v.begin(), v.end()), mid;
	while (min <= max)
	{
		mid = (min + max) / 2;
		int count = 0;
		for (int i = 0; i < n; ++i)
                        count += v[i] > mid ? mid : v[i];

		if (count <= m)
			min = mid + 1;
		else
			max = mid - 1;
	}

	printf("%d", max);
}
