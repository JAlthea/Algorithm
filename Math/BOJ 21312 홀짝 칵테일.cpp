#include <bits/stdc++.h>
using namespace std;

int d[4];

bool cmp(int & a, int & b) {
	int ra = a % 2;
	int rb = b % 2;
	if (ra == rb)
		return a > b;
	return ra > rb;
}

int main() {
	for (int i = 1; i < 4; ++i) {
		cin >> d[i];
	}

	vector<int> ret;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (i && (i == j)) continue;
				if (j && (j == k)) continue;
				if (k && (k == i)) continue;

				int a = (d[i] == 0 ? 1 : d[i]);
				int b = (d[j] == 0 ? 1 : d[j]);
				int c = (d[k] == 0 ? 1 : d[k]);
				ret.push_back(a * b * c);
			}
		}
	}

	sort(ret.begin(), ret.end(), cmp);
	for (auto & i : ret) {
		if (i == 1 && d[1] != 1 && d[2] != 1 && d[3] != 1)
			continue;

		cout << i;
		break;
	}
}
