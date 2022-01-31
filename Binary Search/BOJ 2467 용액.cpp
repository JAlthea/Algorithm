#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int twoSum = INT_MAX;
	int a, b;
	for (int i = 0; i < n - 1; ++i) {
		int k = arr[i];
		int pos = lower_bound(arr.begin() + i + 1, arr.end(), -k) - arr.begin();
		if (pos == n)
			--pos;
		
		if (twoSum > abs(arr[pos] + k)) {
			twoSum = abs(arr[pos] + k);
			a = k;
			b = arr[pos];
		}

		if (arr[pos - 1] != k && twoSum > abs(arr[pos - 1] + k)) {
			twoSum = abs(arr[pos - 1] + k);
			a = k;
			b = arr[pos - 1];
		}
	}

	cout << a << ' ' << b;
}