#include <bits/stdc++.h>
using namespace std;

int n, d[1500001], t[1500001], p[1500001];

int f(int index)
{
	if (index == n) return 0;
	if (index > n) return INT_MIN;
	if (d[index] != -1) return d[index];
	int &ret = d[index];
	return ret = max(f(index + 1), f(index + t[index]) + p[index]);
}

int main()
{
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> t[i] >> p[i];
	cout << f(0);
}
