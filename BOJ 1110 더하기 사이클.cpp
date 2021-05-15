#include <cstdio>
int main()
{
	int n, t, i = 0;
	scanf("%d", &t);
	n = t;
	do
	{
		n = n % 10 * 10 + (n % 10 + n / 10) % 10;
		i++;
	} while (t != n);
	printf("%d", i);
}
