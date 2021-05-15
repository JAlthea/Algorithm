#include <bits/stdc++.h>
using namespace std;

bool v[21][21], s[26];
char d[21][21];
int r, c, ret;
const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

void backTracking(int y, int x, int count) {
	for (int i = 0; i < 4; ++i) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c)
			continue;

		if (s[d[ny][nx] - 'A']) {
			ret = max(ret, count);
			continue;
		}

		if (v[ny][nx])
			continue;

		v[ny][nx] = true;
		s[d[ny][nx] - 'A'] = true;
		backTracking(ny, nx, count + 1);
		s[d[ny][nx] - 'A'] = false;
		v[ny][nx] = false;
	}
}

int main() {

	cin >> r >> c;
	cin.ignore();
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> d[i][j];
		}
	}

	v[0][0] = true;
	s[d[0][0] - 'A'] = true;
	backTracking(0, 0, 1);

	cout << ret;
}
