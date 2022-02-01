#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
    
 	sort(arr.begin(), arr.end());

	long long threeSum = LLONG_MAX;
	long long a, b, c;

	for (int i = 0; i < n - 2; ++i) {
		for (int j = i + 1; j < n - 1; ++j) {
			long long k = arr[i] + arr[j];
			int pos = lower_bound(arr.begin() + j + 1, arr.end(), -k) - arr.begin();
			if (pos == n)
				--pos;
          
			if (threeSum > abs(arr[pos] + k)) {
				threeSum = abs(arr[pos] + k);
				a = arr[i];
				b = arr[j];
				c = arr[pos];
			}
            
			if (pos != j + 1 && threeSum > abs(arr[pos - 1] + k)) {
				threeSum = abs(arr[pos - 1] + k);
				a = arr[i];
				b = arr[j];
				c = arr[pos - 1];
			}
		}
	}

	cout << a << ' ' << b << ' ' << c;
}