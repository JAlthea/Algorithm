#include <ios>

inline int IntSub(int a, int b)
{
	return a - b;
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", IntSub(a, b));
}
