#include <ios>

inline int mul(const int a, const int b)
{
	return a * b;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", mul(a, b));
}
