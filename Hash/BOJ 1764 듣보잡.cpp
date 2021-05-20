#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	map<string, int> h;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		h[s]++;
	}

	int hSize = 0;
	for (int i = 0; i < m; ++i) {
		cin >> s;
		h[s]++;
		if (h[s] == 2)
			++hSize;
	}

	cout << hSize << '\n';
	for (auto & s : h) {
		if (s.second == 2) {
			cout << s.first << '\n';
		}
	}
}
