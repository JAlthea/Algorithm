#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i].first >> arr[i].second;
	sort(arr.begin(), arr.end());
	
	int left = arr[0].first;
	int right = arr[0].second;
	int sum = right - left;
	for (int i = 1; i < n; ++i)
	{
		if (arr[i].first <= right)
		{
			if (arr[i].second <= right) continue;       
			sum += arr[i].second - right;
			right = arr[i].second;
		}
		else
		{
			left = arr[i].first;
			right = arr[i].second;
			sum += right - left;
		}
	}

	cout << sum;
}
