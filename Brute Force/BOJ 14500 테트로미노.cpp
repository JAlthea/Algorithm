#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateBoard(vector<vector<int>> &board, int n, int m)
{
	vector<vector<int>> rotatedBoard(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			rotatedBoard[j][n - 1 - i] = board[i][j];
	return rotatedBoard;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	vector<pair<int, int>> 
		I = { {0, 0}, {0, 1}, {0, 2}, {0, 3} },
		LL = { {0, 0}, {1, 0}, {2, 0}, {2, 1} },
		RL = { {0, 1}, {1, 1}, {2, 1}, {2, 0} },
		LS = { {0, 0}, {1, 0}, {1, 1}, {2, 1} },
		RS = { {0, 1}, {1, 1}, {1, 0}, {2, 0} },
		T = { {0, 0}, {0, 1}, {0, 2}, {1, 1} },
		O = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	vector<vector<pair<int, int>>> tetro;
	tetro.push_back(I);
	tetro.push_back(LL);
	tetro.push_back(RL);
	tetro.push_back(LS);
	tetro.push_back(RS);
	tetro.push_back(T);
	tetro.push_back(O);

	int maxSum = 0;
	for (int k = 0; k < 4; k++)	//rotate
	{
		int N = board.size();
		int M = board[0].size();

		for (int x = 0; x < 7; x++)	//figure
		{
			vector<pair<int, int>> fig = tetro[x];
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					//i, j 방향으로 이동하면서, fig블록 4개의 합을 최신화한다.
					int nowSum = 0;
					for (int c = 0; c < 4; c++)
					{
						if (fig[c].first + i > N - 1 || fig[c].second + j > M - 1)
							break;
						nowSum += board[fig[c].first + i][fig[c].second + j];
					}

					if (nowSum > maxSum)
						maxSum = nowSum;
				}
			}
		}

		board = rotateBoard(board, N, M);
	}

	printf("%d", maxSum);
}
