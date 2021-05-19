#include <bits/stdc++.h>
using namespace std;

int N, r, c, ret;
bool isVisited = false;

bool isPossible(int s1, int e1, int s2, int e2) {
	if (r >= s1 && c >= e1 && r < s2 && c < e2)
		return true;
	return false;
}

void R(int n, int y1, int x1, int y2, int x2, int nCount) {
	if (isVisited)
		return;

	if (n == 1) {
		for (int i = y1; i < y2; ++i) {
			for (int j = x1; j < x2; ++j) {
				if (r == i && c == j) {
					ret = nCount;
					isVisited = true;
					return;
				}
				++nCount;
			}
		}
		return;
	}

	int nPlus = (y2 - y1) / 2 * (x2 - x1) / 2;

	if (isPossible(y1, x1, (y1 + y2) / 2, (x1 + x2) / 2))
		R(n - 1, y1, x1, (y1 + y2) / 2, (x1 + x2) / 2, nCount);
	else if (isPossible(y1, (x1 + x2) / 2, (y1 + y2) / 2, x2))
		R(n - 1, y1, (x1 + x2) / 2, (y1 + y2) / 2, x2, nCount + nPlus);
	else if (isPossible((y1 + y2) / 2, x1, y2, (x1 + x2) / 2))
		R(n - 1, (y1 + y2) / 2, x1, y2, (x1 + x2) / 2, nCount + nPlus * 2);
	else if (isPossible((y1 + y2) / 2, (x1 + x2) / 2, y2, x2))
		R(n - 1, (y1 + y2) / 2, (x1 + x2) / 2, y2, x2, nCount + nPlus * 3);
}

int main() {
	cin >> N >> r >> c;
	R(N, 0, 0, 1 << N, 1 << N, 0);
	cout << ret;
}
