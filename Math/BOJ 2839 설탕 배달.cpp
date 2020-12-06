#include <cstdio>

int d[5001];

int f(int n)
{
	if (n == 0) return 0;
	if (n < 3) return -1;
	if (d[n]) return d[n];

	int c1 = f(n - 5);
	int c2 = f(n - 3);
	if (c1 != -1) c1++;
	if (c2 != -1) c2++;
 
	if (c1 && c2) d[n] = c1 < c2 ? c1 : c2;
	else if (c1) d[n] = c1;
	else if (c2) d[n] = c2;
	else d[n] = -1;

	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
}
