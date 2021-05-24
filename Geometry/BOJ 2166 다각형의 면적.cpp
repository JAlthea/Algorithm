#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<pair<long long, long long>> arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i].first >> arr[i].second;
	}

	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += (arr[i].first + arr[(i + 1) % n].first) * (arr[i].second - arr[(i + 1) % n].second);
	}
	sum = abs(sum);

	cout << fixed;
	cout.precision(1);
	cout << (double)sum / 2;
}
