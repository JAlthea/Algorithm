#include <ios>
#include <vector>
using namespace std;

struct Sudoku {
	int x, y;
	int value = 0;
	int save[10] = { 0 };
};

int d[9][9];
vector<Sudoku> v;
bool success = false;

void setSudoku(Sudoku & now) {
	for (int i = 0; i < 9; ++i)
		++now.save[d[i][now.y]];

	for (int i = 0; i < 9; ++i)
		++now.save[d[now.x][i]];

	int X = now.x / 3 * 3;
	int Y = now.y / 3 * 3;
	for (int i = X; i < X + 3; ++i)
		for (int j = Y; j < Y + 3; ++j)
			++now.save[d[i][j]];
}

bool checkSudoku(Sudoku & now) {
	for (int i = 0; i < 9; ++i)
		if (now.value == d[i][now.y])
			return false;

	for (int i = 0; i < 9; ++i)
		if (now.value == d[now.x][i])
			return false;

	int X = now.x / 3 * 3;
	int Y = now.y / 3 * 3;
	for (int i = X; i < X + 3; ++i)
		for (int j = Y; j < Y + 3; ++j)
			if (now.value == d[i][j])
				return false;
	
	return true;
}

void backTrackingSudoku(int pos) {
	if (pos >= v.size()) {
		success = true;
		return;
	}

	for (int j = 1; j <= 9; ++j) {
		if (success)
			return;

		if (v[pos].save[j] == 0) {
			v[pos].value = j;
			if (checkSudoku(v[pos])) {
				d[v[pos].x][v[pos].y] = v[pos].value;
				backTrackingSudoku(pos + 1);
			}
		}
	}

	if (success)
		return;

	d[v[pos].x][v[pos].y] = 0;
}

int main() {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			scanf("%d", &d[i][j]);
			if (d[i][j] == 0) {
				Sudoku tmp;
				tmp.x = i;
				tmp.y = j;
				v.push_back(tmp);
			}
		}
	}

	for (int i = 0; i < v.size(); ++i)
		setSudoku(v[i]);

	backTrackingSudoku(0);
	
	for (int i = 0; i < 9; puts(""), ++i)
		for (int j = 0; j < 9; ++j)
			printf("%d ", d[i][j]);
}
