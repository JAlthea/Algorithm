#include <bits/stdc++.h>
using namespace std;

int n, d[16], t[16], p[16];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> t[i] >> p[i];
	}

	for (int i = 0; i < n; ++i) {
		d[i + 1] = max(d[i + 1], d[i]);
		if (i + t[i] <= n) {
			d[i + t[i]] = max(d[i + t[i]], d[i] + p[i]);
		}
	}

	cout << d[n];
}
