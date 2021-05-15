#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr)
{
	for (int i = 0; i < arr.size(); i++)
		printf("%d\n", arr[i]);
}

void simulation(vector<vector<int>> &board, pair<int, int> &pos, vector<int> &command)
{
	int n = board.size();
	int m = board[0].size();
	int dice_hor[4] = { 0, 0, 0, 0 };
	int dice_ver[4] = { 0, 0 ,0 ,0 };
	int indexH = 1;
	int indexV = 1;
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { 1, -1, 0, 0 };
	int x = pos.first;
	int y = pos.second;
	vector<int> printDice;
	for (int i = 0; i < command.size(); i++)
	{
		int nx = x + dx[command[i] - 1];
		int ny = y + dy[command[i] - 1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;

		x = nx;
		y = ny;
		if (command[i] == 1)	// P -> Right
		{
			if (indexH == 3)
				indexH = 0;
			else
				indexH++;

			if (board[x][y] == 0)
				board[x][y] = dice_hor[indexH];
			else
			{
				dice_hor[indexH] = board[x][y];
				board[x][y] = 0;
			}

			dice_ver[indexV] = dice_hor[indexH];	//밑변 최신화
			dice_ver[(indexV + 2) % 4] = dice_hor[(indexH + 2) % 4];	//윗면 최신화

			printDice.push_back(dice_hor[(indexH + 2) % 4]);
		}
		else if (command[i] == 2)	// P -> Left
		{
			if (indexH == 0)
				indexH = 3;
			else
				indexH--;

			if (board[x][y] == 0)
				board[x][y] = dice_hor[indexH];
			else
			{
				dice_hor[indexH] = board[x][y];
				board[x][y] = 0;
			}

			dice_ver[indexV] = dice_hor[indexH];	//밑변 최신화
			dice_ver[(indexV + 2) % 4] = dice_hor[(indexH + 2) % 4];	//윗면 최신화

			printDice.push_back(dice_hor[(indexH + 2) % 4]);
		}
		else if (command[i] == 3)	// P -> Top
		{
			if (indexV == 0)
				indexV = 3;
			else
				indexV--;

			if (board[x][y] == 0)
				board[x][y] = dice_ver[indexV];
			else
			{
				dice_ver[indexV] = board[x][y];
				board[x][y] = 0;
			}

			dice_hor[indexH] = dice_ver[indexV];	//밑변 최신화
			dice_hor[(indexH + 2) % 4] = dice_ver[(indexV + 2) % 4];	//윗면 최신화

			printDice.push_back(dice_ver[(indexV + 2) % 4]);
		}
		else if (command[i] == 4)	// P -> Bottom
		{
			if (indexV == 3)
				indexV = 0;
			else
				indexV++;

			if (board[x][y] == 0)
				board[x][y] = dice_ver[indexV];
			else
			{
				dice_ver[indexV] = board[x][y];
				board[x][y] = 0;
			}

			dice_hor[indexH] = dice_ver[indexV];	//밑변 최신화
			dice_hor[(indexH + 2) % 4] = dice_ver[(indexV + 2) % 4];	//윗면 최신화

			printDice.push_back(dice_ver[(indexV + 2) % 4]);
		}
	}

	printArray(printDice);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	
	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	pair<int, int> pos = { x, y };
	
	vector<int> command(k, 0);
	for (int i = 0; i < k; i++)
		cin >> command[i];

	simulation(board, pos, command);
}
