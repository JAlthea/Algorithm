#include <cstdio>
int n, s, x, m;
int main() 
{
	scanf("%d", &n);
	while (~scanf("%d", &s))
	{
		if (m < s) m = s;
		x += s;
	}
	printf("%f", (float)x / n / m * 100.0);
}
