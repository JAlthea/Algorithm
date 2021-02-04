#include <ios>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		double a, b, c, ret = 1;
		scanf("%d%d", &n, &m);
		a = m; b = n; c = m - n;
		while (a > c && b > 1)
		{
			ret *= a / b;
			--a; --b;
		}

		while (a > c)
		{
			ret *= a;
			--a;
		}

		while (b > 1)
		{
			ret /= b;
			--b;
		}

		printf("%.0lf\n", ret);
	}
}
