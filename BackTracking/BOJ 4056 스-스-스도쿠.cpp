#include <bits/stdc++.h>
using namespace std;

int maxCount;
char d[9][9];
bool v[9][9];
bool isSuccess;

bool isSudoku(int y, int x, char value) {
	for (int i = 0; i < 9; i++) {
		if (i == y)
			continue;

		if (value == d[i][x])
			return false;
	}

	for (int i = 0; i < 9; i++) {
		if (i == x)
			continue;

		if (value == d[y][i])
			return false;
	}

	int ny = y / 3 * 3;
	int nx = x / 3 * 3;
	for (int i = ny; i < ny + 3; i++) {
		for (int j = nx; j < nx + 3; j++) {
			if (i == y && j == x)
				continue;

			if (value == d[i][j])
				return false;
		}
	}

	return true;
}

bool isCompletedSudoku() {
	if (!isSuccess)
		return false;

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (d[i][j] == '0' || !isSudoku(i, j, d[i][j]))
				return false;
		}
	}

	return true;
}

void backTrackingSudoku(int y, int x, int count) {
	if (count == maxCount) {
		isSuccess = true;
		return;
	}

	if (!v[y][x]) {
		if (x == 8)
			backTrackingSudoku(y + 1, 0, count);
		else
			backTrackingSudoku(y, x + 1, count);
	}
	else {
		for (int k = 1; k <= 9; ++k) {
			if (isSudoku(y, x, k + '0'))
				d[y][x] = k + '0';
			else
				continue;

			if (x == 8)
				backTrackingSudoku(y + 1, 0, count + 1);
			else
				backTrackingSudoku(y, x + 1, count + 1);

			if (isSuccess)
				return;
		}

		d[y][x] = '0';
	}
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		memset(v, 0, sizeof(v));
		isSuccess = false;
		maxCount = 0;

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				cin >> d[i][j];
				if (d[i][j] == '0') {
					++maxCount;
					v[i][j] = true;
				}
			}
		}

		backTrackingSudoku(0, 0, 0);

		if (!isCompletedSudoku()) {
			cout << "Could not complete this grid.\n\n";
			continue;
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j)
				cout << d[i][j];
			cout << '\n';
		}
		cout << '\n';
	}
}