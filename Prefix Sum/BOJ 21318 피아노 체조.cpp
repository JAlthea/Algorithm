#include <bits/stdc++.h>
using namespace std;

int d[100001], s[100001], dSum[100002];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q, l, r;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		s[i] = (d[i] > d[i + 1] ? 1 : 0);
	}
	
	for (int i = 0; i < n; ++i) {
		dSum[i + 1] = dSum[i] + s[i];
	}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << dSum[r - 1] - dSum[l - 1] << '\n';
	}
}
