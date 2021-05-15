#include <cstdio>

inline int mySum(const int a, contst int b) { return a + b; }

int main()
{
	int a, b, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", mySum(a, b));
	}
}
