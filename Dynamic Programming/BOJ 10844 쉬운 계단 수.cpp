#include <cstdio>
#define D 1000000000

int d[10], c[10], n, i, j, s;

int main()
{
	for(i=1; i<10; i++) d[i]++, c[i]++;
	scanf("%d", &n);
	for(i=2; i<=n; i++)
	{
		for(j=0; j<10; j++)
		{
			if(!j) d[j] = c[1];
			else if(j==9) d[j] = c[8];
			else d[j] = c[j-1] + c[j+1];
			d[j] %= D;
		}
		for(j=0; j<10; j++) c[j] = d[j];
	}
	for(i=0; i<10; i++) s = (s + d[i]) % D;
	printf("%d", s % D);
}
