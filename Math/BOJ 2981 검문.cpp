#include <ios>
#include <algorithm>
using namespace std;

int n, d[100], s[999];

int gcd(int a, int b)
{
	return a % b ? gcd(b, a%b) : b;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);
	sort(d, d + n);

	int gap = d[1] - d[0];
	int k = gap;
	for (int i = 2; i < n; i++)
	{
		gap = d[i] - d[i - 1];
		k = gcd(k, gap);
	}

	int j = 0;
	for (int i = 2; i*i <= k; i++)
	{
		if (k % i == 0)
		{
			s[j++] = i;
			if (k / i != i)
				s[j++] = k / i;
		}
	}
	s[j] = k;
	sort(s, s + j + 1);

	for (int i = 0; i < j + 1; i++)
		printf("%d ", s[i]);
}
