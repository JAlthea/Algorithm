#include <bits/stdc++.h>
using namespace std;

int d[10001], p[10001], z[10001], m[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];

	sort(d, d + n, greater<int>());

	int pIndex = 0, zIndex = 0, mIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] > 0)
			p[pIndex++] = d[i];
		else if (d[i] == 0)
			z[zIndex++] = d[i];
		else
			m[mIndex++] = d[i];
	}

	int ret = 0;
	for (int i = 0; i < pIndex; ++i) {
		if (i == pIndex - 1 || p[i] == 1 || p[i + 1] == 1) {
			ret += p[i];
			continue;
		}

		ret += p[i] * p[i + 1];
		++i;
	}

	if (mIndex % 2 && !zIndex)
		ret += m[0];

	for (int i = mIndex - 1; i >= mIndex % 2; i -= 2)
		ret += m[i] * m[i - 1];
    
	cout << ret;
}
