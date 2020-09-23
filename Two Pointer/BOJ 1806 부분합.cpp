#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> arr(n + 1, 0);
	vector<int> arrSum(n + 1, 0);
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	for (int i = 1; i <= n; ++i)
		arrSum[i] = arrSum[i - 1] + arr[i];

	int answer = INT_MAX;
	int start = 1;
	int end = 1;
	while (start <= n && end <= n)
	{
		if (arrSum[n] - arrSum[start - 1] < s)
			break;

		while (end < n && arrSum[end] - arrSum[start - 1] < s)
			end++;
		
		if (arrSum[end] - arrSum[start - 1] >= s)
			answer = min(answer, end - start + 1);

		start++;
		if (start == end + 1)
			end++;
	}

	cout << (answer == INT_MAX ? 0 : answer);
}
