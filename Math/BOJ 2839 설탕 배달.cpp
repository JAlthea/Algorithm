#include <cstdio>

int d[5001];

int f(int n)
{
	if (n == 0) return 0;
	if (n < 3) return -1;
	if (d[n] > 0) return d[n];

	int c1 = n >= 5 ? f(n - 5) : 0;
	int c2 = n >= 3 ? f(n - 3) : 0;
	if (n >= 5 && c1 != -1) c1++;
	if (n >= 3 && c2 != -1) c2++;
 
	if (c1 > 0 && c2 > 0) d[n] = c1 < c2 ? c1 : c2;
	else if (c1 > 0) d[n] = c1;
	else if (c2 > 0) d[n] = c2;
	else d[n] = -1;

	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
}
