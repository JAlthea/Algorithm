#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n) {
	vector<int> answer;

	vector<vector<int>> board(n);
	for (int i = 0; i < n; ++i)
		board[i].resize(i + 1);

	int max = 0;
	for (int i = 1; i <= n; ++i)
		max += i;

	int startY = 0;
	int endY = n - 1;
	int startX = 0;
	int endX = n - 1;
	int number = 1;
	while (number < max + 1) {   //triangle 1 cycle
		for (int i = startY; i <= endY; ++i)    //아래로 이동
			board[i][startX] = number++;

		for (int i = startX + 1; i <= endX; ++i)    //왼쪽에서 오른쪽 이동
			board[endY][i] = number++;

		for (int i = endY - 1, j = endX - 1; i > startY && j > startX; --i, --j)    //대각선 위로 이동
			board[i][j] = number++;

		startY += 2;
		endY--;
		startX++;
		endX -= 2;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < board[i].size(); ++j)
			answer.push_back(board[i][j]);

	return answer;
}
