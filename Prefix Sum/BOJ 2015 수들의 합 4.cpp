#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> arr(n, 0);
	vector<int> arrSum(n + 1, 0);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	for (int i = 1; i <= n; ++i) arrSum[i] = arrSum[i - 1] + arr[i - 1];

	unordered_map<int, long long> m;
	long long answer = 0;
	for (int i=1; i<=n; ++i)
	{
		if (arrSum[i] == k) answer++;
		answer += m[arrSum[i] - k];
		m[arrSum[i]]++;
	}

	cout << answer;
}
