#include <ios>

int n, m, d[8];

void f(int pos)
{
	if (m == pos)
	{
		for (int i = 0; i < m; i++)
			printf("%d ", d[i]);
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		d[pos] = i;
		f(pos + 1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	f(0);
}
