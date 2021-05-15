#include <ios>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c;
		scanf("%d%d", &a, &b);

		c = a;
		b = b % 4 + 4;

		for (int i = 2; i <= b; ++i) 
			c = (c * a) % 10;
		printf("%d\n", c ? c : 10);
	}
}
