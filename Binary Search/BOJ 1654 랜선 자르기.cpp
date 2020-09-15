#include <ios>
#include <vector>
using namespace std;

int main()
{
	vector<long long> v;
	long long sum = 0 , i, k, n, max, min, mid, c, res = 0;
	scanf("%lld%lld", &k, &n);
	v.resize(k);
	for (i = 0; i < v.size(); sum += v[i], ++i)
		scanf("%lld", &v[i]);
	max = sum / n;
	min = 1;
	while (min <= max)
	{
		mid = (max + min) / 2;
		c = 0;
		for (i = 0; i < v.size(); ++i)
			c += v[i] / mid;

		if (c >= n)
		{
			if (res < mid)
				res = mid;
			min = mid + 1;
		}
		else if (c < n)
			max = mid - 1;
	}
	printf("%lld", res);
}
