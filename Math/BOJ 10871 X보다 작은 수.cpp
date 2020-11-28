#include <cstdio>
int main()
{
	int a, b, c;
	scanf("%d %d", &a, &b);
	while (~scanf("%d", &c))
		if (b > c) printf("%d ", c);
}
