#import <ios>

int main()
{
	int n, m, d[99];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &d[i]);

	int sum = m;
	int min = 999999;
	for (int i = 0; i < n; i++)
	{
		if (m - d[i] < 2)
			continue;

		int a = sum - d[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a - d[j] < 1)
				continue;
			
			int b = a - d[j];
			for (int k = j + 1; k < n; k++)
			{
				if (b - d[k] < 0)
					continue;

				if (min > b - d[k])
					min = b - d[k];
			}
		}
	}

	printf("%d", m - min);
}
