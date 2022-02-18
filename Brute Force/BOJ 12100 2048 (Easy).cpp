#include <bits/stdc++.h>
using namespace std;

const int UP = 1;
const int DOWN = 2;
const int LEFT = 3;
const int RIGHT = 4;
int maxBlock;

int checkBoard(vector<vector<int>> &board) {
	int value = 0;
	for (int i = 0; i < board.size(); ++i)
		for (int j = 0; j < board.size(); ++j)
			value = max(value, board[i][j]);
	return value;
}

vector<vector<int>> collide(vector<vector<int>> &board, int direction) {
	int n = board.size();
	vector<vector<int>> newBoard = board;
	vector<vector<int>> saveBlock(n, vector<int>(n, 0));
	
	if (direction == UP) {
		// Part1. 위부터 아래로 검사해서 같은 라인에 있는게 있으면 우선적으로 합체
		for (int j = 0; j < n; ++j) {
			int p1 = 0, p2 = 0;
			int index = 0;
			for (int i = 0; i < n; ++i) {
				if (newBoard[i][j]) {
					if (p1 == 0)
						p1 = newBoard[i][j];
					else if (p2 == 0)
						p2 = newBoard[i][j];
				}

				// Block checking
				if (p1 && p2) {
					if (p1 == p2) {
						saveBlock[index++][j] = p1 + p2;
						p1 = 0; p2 = 0;
					}
					else {
						saveBlock[index++][j] = p1;
						p1 = p2; p2 = 0;
					}
				}
			}

			saveBlock[index][j] = p1;
		}

		newBoard = saveBlock;
	}
	else if (direction == DOWN) {
		// Part1. 아래부터 위로 검사해서 같은 라인에 있는게 있으면 우선적으로 합체
		for (int j = 0; j < n; ++j) {
			int p1 = 0, p2 = 0;
			int index = n - 1;
			for (int i = n - 1; i >= 0; --i) {
				if (newBoard[i][j]) {
					if (p1 == 0)
						p1 = newBoard[i][j];
					else if (p2 == 0)
						p2 = newBoard[i][j];
				}

				// Block checking
				if (p1 && p2) {
					if (p1 == p2) {
						saveBlock[index--][j] = p1 + p2;
						p1 = 0; p2 = 0;
					}
					else {
						saveBlock[index--][j] = p1;
						p1 = p2; p2 = 0;
					}
				}
			}

			saveBlock[index][j] = p1;
		}

		newBoard = saveBlock;
	}
	else if (direction == LEFT) {
		// Part1. 왼쪽부터 오른쪽으로 검사해서 같은 라인에 있는게 있으면 우선적으로 합체
		for (int i = 0; i < n; ++i) {
			int p1 = 0, p2 = 0;
			int index = 0;
			for (int j = 0; j < n; ++j) {
				if (newBoard[i][j]) {
					if (p1 == 0)
						p1 = newBoard[i][j];
					else if (p2 == 0)
						p2 = newBoard[i][j];
				}

				// Block checking
				if (p1 && p2) {
					if (p1 == p2) {
						saveBlock[i][index++] = p1 + p2;
						p1 = 0; p2 = 0;
					}
					else {
						saveBlock[i][index++] = p1;
						p1 = p2; p2 = 0;
					}
				}
			}

			saveBlock[i][index] = p1;
		}

		newBoard = saveBlock;
	}
	else if (direction == RIGHT) {
		// Part1. 오른쪽부터 왼쪽으로 검사해서 같은 라인에 있는게 있으면 우선적으로 합체
		for (int i = 0; i < n; ++i) {
			int p1 = 0, p2 = 0;
			int index = n - 1;
			for (int j = n - 1; j >= 0; --j) {
				if (newBoard[i][j]) {
					if (p1 == 0)
						p1 = newBoard[i][j];
					else if (p2 == 0)
						p2 = newBoard[i][j];
				}

				// Block checking
				if (p1 && p2) {
					if (p1 == p2) {
						saveBlock[i][index--] = p1 + p2;
						p1 = 0; p2 = 0;
					}
					else {
						saveBlock[i][index--] = p1;
						p1 = p2; p2 = 0;
					}
				}
			}

			saveBlock[i][index] = p1;
		}

		newBoard = saveBlock;
	}

	return newBoard;
}

void backTracking(vector<vector<int>> &board, int depth) {
	if (depth == 5) {
		maxBlock = max(maxBlock, checkBoard(board));
		return;
	}

	vector<vector<int>> newBoard;

	newBoard = collide(board, UP);
	backTracking(newBoard, depth + 1);

	newBoard = collide(board, DOWN);
	backTracking(newBoard, depth + 1);

	newBoard = collide(board, LEFT);
	backTracking(newBoard, depth + 1);

	newBoard = collide(board, RIGHT);
	backTracking(newBoard, depth + 1);
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> board[i][j];
	backTracking(board, 0);
	cout << maxBlock;
}
