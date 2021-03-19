#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		long long a, b, n;
		cin >> a >> b;
		n = a + b;
		cout << n * n * (n - 1) / 2 << '\n';
	}
}
