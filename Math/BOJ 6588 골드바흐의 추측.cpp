#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
int d[MAX];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	for (int i = 2; i * i <= MAX; ++i)
		if (!d[i])
			for (int j = i + i; j <= MAX; j += i)
				++d[j];

	while (1)
	{
		int n;
		cin >> n;
		if (!n) break;
		for (int a = 3; a <= n / 2; a += 2)
		{
			if (d[a] || d[n - a]) continue;
			cout << n << " = " << a << " + " << n - a << '\n';
			break;
		}
	}
}
