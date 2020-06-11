#include <cstdio>

int d[5001];

int f(int n)
{
	if (n == 0)
		return 0;
	if (n < 3)
		return -1;
	if (d[n] > 0)
		return d[n];

	int count = 0, count2 = 0;

	if (n >= 5)
	{
		count = f(n - 5);
		if (count != -1)
			count++;
	}
	if (n >= 3)
	{
		count2 = f(n - 3);
		if (count2 != -1)
			count2++;
	}
 
	if (count > 0 && count2 > 0)
		d[n] = count < count2 ? count : count2;
	else if (count > 0)
		d[n] = count;
	else if (count2 > 0)
		d[n] = count2;
	else
		d[n] = -1;

	return d[n];
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", f(n));
}
