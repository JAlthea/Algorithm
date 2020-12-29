#import <ios>
int d[10001], i, a, b, s;
int main()
{
	for (i=1; i*i<10001; ++i) d[i * i]++;
	scanf("%d%d", &a, &b);
	for (i=b; a<=b; ++a)
	{
		if (d[a])
		{
			if (a < i) i = a;
			s += a;
		}
	}
	s ? printf("%d\n%d", s, i) : puts("-1");
}
