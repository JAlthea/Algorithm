#include <ios>

int n, m, d[9];
bool check[9];
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
		if (!check[i])
		{
			check[i] = true;
			d[pos] = i;
			f(pos + 1);
			check[i] = false;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	f(0);
}
