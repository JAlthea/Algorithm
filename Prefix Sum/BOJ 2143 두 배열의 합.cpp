#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, m;

	cin >> t >> n;
	vector<int> a(n), aSum(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		aSum[i + 1] = aSum[i] + a[i];
	}

	cin >> m;
	vector<int> b(m), bSum(m + 1);
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		bSum[i + 1] = bSum[i] + b[i];
	}

	vector<int> aSSum;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			int k = aSum[i] - aSum[j];
			aSSum.push_back(k);
		}
	}

	vector<int> bSSum;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < i; ++j) {
			int k = bSum[i] - bSum[j];
			bSSum.push_back(k);
		}
	}

	sort(bSSum.begin(), bSSum.end());

	long long ret = 0;
	for (int i = 0; i < aSSum.size(); ++i) {
		int k = aSSum[i];
		auto p = equal_range(bSSum.begin(), bSSum.end(), t - k);
		ret += p.second - p.first;
	}

	cout << ret;
}
