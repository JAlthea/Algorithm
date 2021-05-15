#import<ios>
int t, m, n, x, y, a, b, k;
inline int GCD(int a, int b) { return a % b ? GCD(b, a % b) : b; }
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &m, &n, &x, &y);
		a = b = x;
		for (int i = 0; i < n; ++i)
		{
			k = b % n ? b % n : n;
			if (k == y) break;
			b = k + m;
			a += m;
		}
		printf("%d\n", a > m * n / GCD(m, n) ? -1 : a);
	}
}
