#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

struct cmp {
	size_t operator()(const vector<int> &a, const vector<int> &b) const {
		return a[2] < b[2];
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int h, w;
		cin >> h >> w;
		cin.ignore();
		vector<vector<char>> board(h, vector<char>(w));    // 2D Map

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				cin >> board[i][j];
			}
		}
		cin.ignore();

		int keys[27] = { 0 };    // Key for unlock
		string str;
		getline(cin, str);
		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == '0')
				break;
			keys[str[i] - 'a'] = 1;
		}

		vector<pair<int, int>> locks[27];    // Locked position
		vector<vector<bool>> visited(h, vector<bool>(w, false));
		int ret = 0;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (i != 0 && i != h - 1 && j != 0 && j != w - 1)
					continue;

				if (visited[i][j] || board[i][j] == '*')
					continue;

				if (islower(board[i][j]))
					keys[board[i][j] - 'a'] = 1;

				if (isupper(board[i][j]) && keys[tolower(board[i][j]) - 'a'] == 0) {
					locks[tolower(board[i][j]) - 'a'].push_back({ i, j });
					continue;
				}

				visited[i][j] = true;
				priority_queue<vector<int>, vector<vector<int>>, cmp> q;
				q.push({ i, j, isupper(board[i][j]) ? -1 : 1 });

				vector<int> v;
				while (!q.empty()) {
					v = q.top(); q.pop();
					int y = v[0];
					int x = v[1];
					int po = v[2];

					if (board[y][x] == '$')
						++ret;

					if (islower(board[y][x]))
						keys[board[y][x] - 'a'] = 1;

					if (isupper(board[y][x]) && keys[tolower(board[y][x]) - 'a'] == 0) {
					    locks[tolower(board[y][x]) - 'a'].push_back({ y, x });
						continue;
					}

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= h || nx >= w)
							continue;
						
						if (visited[ny][nx] || board[ny][nx] == '*')
							continue;

						visited[ny][nx] = true;
						q.push({ ny, nx, isupper(board[ny][nx]) ? -1 : 1 });
					}
				}
			}
		}
		
		for (int i = 0; i < 26; ++i) {
			if (keys[i] != 1)
				continue;

			int researchIndex = -1;
			keys[i] = -1;
			for (int j = locks[i].size() - 1; j >= 0; --j) {
				auto[a, b] = locks[i][j];

				priority_queue<vector<int>, vector<vector<int>>, cmp> q;
				q.push({ a, b, isupper(board[a][b]) ? -1 : 1 });

				vector<int> v;
				while (!q.empty()) {
					v = q.top(); q.pop();
					int y = v[0];
					int x = v[1];
					int po = v[2];

					if (board[y][x] == '$')
						++ret;

					if (islower(board[y][x]) && keys[board[y][x] - 'a'] == 0) {
						keys[board[y][x] - 'a'] = 1;
                        if (researchIndex == -1)
                            researchIndex = board[y][x] - 'a';
                        researchIndex = min(researchIndex, board[y][x] - 'a');
					}

					if (isupper(board[y][x]) && keys[tolower(board[y][x]) - 'a'] == 0) {
				        locks[tolower(board[y][x]) - 'a'].push_back({ y, x });
					    continue;
					}

					for (int k = 0; k < 4; ++k) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if (ny < 0 || nx < 0 || ny >= h || nx >= w)
							continue;

						if (visited[ny][nx] || board[ny][nx] == '*')
							continue;

						visited[ny][nx] = true;
						q.push({ ny, nx, isupper(board[ny][nx]) ? -1 : 1 });
					}
				}
			}

			if (researchIndex != -1) {
				keys[researchIndex] = 1;
				if (i < researchIndex)
					continue;
				i = researchIndex - 1;
			}
		}

		cout << ret << '\n';
	}
}