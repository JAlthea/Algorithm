#include <bits/stdc++.h>
using namespace std;

int d[21][2], n, k, ret = (int)1e9;
bool isSuperJump = true;

void backTracking(int index, int count) {
	if (index == n - 1) {
		ret = min(ret, count);
		return;
	}

	for (int i = index + 1; i <= index + 3 && i < n; ++i) {
		if (i == index + 3) {
			if (!isSuperJump)
                break;
			
			isSuperJump = false;
			backTracking(i, count + k);
			isSuperJump = true;
			continue;
		}
		
		backTracking(i, count + d[index][i - 1 - index]);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		cin >> d[i][0] >> d[i][1];
	}
	cin >> k;

	backTracking(0, 0);
	cout << ret;
}
