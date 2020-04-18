#include <cstdio>
long long d[91], n;
int main() 
{
	scanf("%d", &n);
	d[1] = 1;
	for (int i=2; i<=n; i++)
        d[i] = d[i-1] + d[i-2];
	printf("%lld", d[n]);
}
