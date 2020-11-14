#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, a, b;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> pSum(n + 1);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 1; i <= n; ++i) pSum[i] = arr[i - 1] + pSum[i - 1];
	while (m--)
	{
		cin >> a >> b;
		cout << pSum[b] - pSum[a - 1] << '\n';
	}
}
