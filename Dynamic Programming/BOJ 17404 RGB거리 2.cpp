#include <bits/stdc++.h>
using namespace std;

int n, d[1002][3], c[1002][3];
bool startCheck[3];

long long dp(int i, int color) {
	int & ret = c[i][color];
	if (ret) {
		return ret;
	}

	if (i == n - 1) {
		return startCheck[color] ? INT_MAX : d[i][color];
	}
	
	if (i == 0) {
		startCheck[color] = true;
	}
	
	return ret = min(dp(i + 1, (color + 1) % 3), dp(i + 1, (color + 2) % 3)) + d[i][color];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i][0] >> d[i][1] >> d[i][2];
	}

	int m1 = dp(0, 0);
	memset(c, 0, sizeof(c));
	memset(startCheck, 0, sizeof(startCheck));

	int m2 = dp(0, 1);
	memset(c, 0, sizeof(c));
	memset(startCheck, 0, sizeof(startCheck));

	int m3 = dp(0, 2);
	
	cout << min(m1, min(m2, m3));
}
