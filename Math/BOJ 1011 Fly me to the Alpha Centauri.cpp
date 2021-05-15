#include <cstdio>

int t, x, y;
int main() 
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &x, &y);
		int dis = y - x;
		int p = 0;
		unsigned int s = 0;
		int n = 0;
		while (dis > s)
		{
			p += 2;
			s += p;
			++n;
		}

		if (dis <= s - n)
			printf("%d\n", 2 * n - 1);
		else
			printf("%d\n", 2 * n);
	}
}
