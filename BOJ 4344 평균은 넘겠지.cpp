#include <cstdio>

int main()
{
	int c, n, s, count, d[1001];
	float m;

	for (scanf("%d", &c); ~scanf("%d", &n);)
	{
		s = 0; count = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &d[i]);
			s += d[i];
		}
    
		m = (float)s / n;
		for (int i = 0; i < n; ++i)
			if (d[i] > m) count++;
      
		printf("%.3f%\n", (float)count / n * 100);
	}
}
