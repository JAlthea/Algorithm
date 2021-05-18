#include <bits/stdc++.h>
using namespace std;

int d[1002][1002];
string a, b, ret = "";

void rebuild(int aIndex, int bIndex) {
	if (aIndex == 0 || bIndex == 0)
		return;

	if (a[aIndex - 1] == b[bIndex - 1]) {
		ret += a[aIndex - 1];
		rebuild(aIndex - 1, bIndex - 1);
	}
	else {
		if (d[aIndex - 1][bIndex] >= d[aIndex][bIndex - 1])
			rebuild(aIndex - 1, bIndex);
		else
			rebuild(aIndex, bIndex - 1);
	}
}

int main() {
	cin >> a >> b;

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			if (a[i] == b[j])
				d[i + 1][j + 1] = d[i][j] + 1;
			else
				d[i + 1][j + 1] = max(d[i + 1][j], d[i][j + 1]);
		}
	}

	rebuild(a.size(), b.size());
	reverse(ret.begin(), ret.end());

	cout << d[a.size()][b.size()] << '\n';
	cout << ret;
}
