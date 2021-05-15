#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n), pSum(n + 1), leftMin(n + 1), rightMax(n + 2);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	if (n == 1)
	{
		cout << arr[0];
		return 0;
	}

	for (int i = 1; i <= n; ++i)
		pSum[i] = pSum[i - 1] + arr[i - 1];

	leftMin[0] = 0;
	for (int i = 1; i <= n; ++i)
		leftMin[i] = min(leftMin[i - 1], pSum[i]);

	rightMax[n + 1] = pSum[n] + arr[n - 1];
	rightMax[n] = pSum[n];
	for (int i = n - 1; i >= 1; --i)
		rightMax[i] = max(rightMax[i + 1], pSum[i]);

	int maxValue = INT_MIN / 2;
	for (int i = 1; i <= n; ++i)
	{
		int noSum = pSum[i] - leftMin[i - 1];
		int yesSum = rightMax[i + 1] + (-1 * arr[i - 1]) - leftMin[i - 1];
		maxValue = max(maxValue, max(noSum, yesSum));
	}

	cout << maxValue;
}
