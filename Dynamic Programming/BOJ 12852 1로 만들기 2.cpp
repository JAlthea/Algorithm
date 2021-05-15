#include <bits/stdc++.h>
using namespace std;

int d[1000001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for (int i = 2; i <= n; ++i) {
		int a = d[i - 1] + 1;
		int b = i % 2 ? INT_MAX : d[i / 2] + 1;
		int c = i % 3 ? INT_MAX : d[i / 3] + 1;
		d[i] = min(a, min(b, c));
	}

	vector<int> backRoutes;
	backRoutes.push_back(n);
	int i = n;
	while (i > 1) {
		int a = d[i - 1];
		int b = i % 2 ? INT_MAX : d[i / 2];
		int c = i % 3 ? INT_MAX : d[i / 3];
		int nextRoute = min(a, min(b, c));

		if (nextRoute == a) {
			backRoutes.push_back(i - 1);
			--i;
		}
		else if (nextRoute == b) {
			backRoutes.push_back(i / 2);
			i /= 2;
		}
		else {
			backRoutes.push_back(i / 3);
			i /= 3;
		}
	}

	cout << d[n] << '\n';
	for (auto & i : backRoutes) {
		cout << i << ' ';
	}
}
