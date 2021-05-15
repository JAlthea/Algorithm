#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin.ignore();
	vector<vector<char>> board(n, vector<char>(m));
	pair<int, int> redBall;
	pair<int, int> blueBall;
	pair<int, int> goal;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
				redBall = { i, j };
			else if (board[i][j] == 'B')
				blueBall = { i, j };
			else if (board[i][j] == 'O')
				goal = { i, j };
		}
	}

	set<vector<int>> s;
	const int dy[] = { 0, 0, 1, -1 };
	const int dx[] = { 1, -1, 0, 0 };
	queue<vector<int>> q;
	q.push({ 0, redBall.first, redBall.second, blueBall.first, blueBall.second });
	while (!q.empty())
	{
		vector<int> v = q.front(); q.pop();
		int count = v[0];
		int ry = v[1];
		int rx = v[2];
		int by = v[3];
		int bx = v[4];

		if (count > 9)
		{
			cout << -1;
			return 0;
		}

		if (s.find({ ry, rx, by, bx }) != s.end())
			continue;
		s.insert({ ry, rx, by, bx });

		//4방향을 기준으로 goal을 만나는지 확인
		for (int i = 0; i < 4; i++)
		{
			int nry = ry;
			int nrx = rx;
			int nby = by;
			int nbx = bx;

			//빨간 공과 파란 공을 동시에 고려한 시뮬레이션
			bool isFailed = false;
			while (1)
			{
				if (board[nry][nrx] == 'O')    //빨간 공 탈출 조건 (성공)
					break;

				if (board[nby][nbx] == 'O')    //파란 공 탈출 조건 (실패)
				{
					isFailed = true;
					break;
				}

				//탈출 조건 : 둘다 움직이지 않을 때
				bool isEscapeA = true;
				bool isEscapeB = true;

				nry += dy[i];
				nrx += dx[i];
				if (nry == nby && nrx == nbx)    //빨간 공이 파란 공과 만날 때
				{
					nry -= dy[i];
					nrx -= dx[i];
				}
				else if (board[nry][nrx] == '#')
				{
					nry -= dy[i];
					nrx -= dx[i];
				}
				else
					isEscapeA = false;
				
				nby += dy[i];
				nbx += dx[i];
				if (nby == nry && nbx == nrx)    //파란 공이 빨간 공과 만날 때
				{
					nby -= dy[i];
					nbx -= dx[i];
				}
				else if (board[nby][nbx] == '#')
				{
					nby -= dy[i];
					nbx -= dx[i];
				}
				else
					isEscapeB = false;

				if (isEscapeA && isEscapeB)
					break;
			}

			while (board[nby][nbx] != '#' && (nby != nry || nbx != nrx))	//빨간 공과 파란 공이 동시에 탈출하는 경우인지
			{
				nby += dy[i];
				nbx += dx[i];
				if (board[nby][nbx] == 'O')
					isFailed = true;
			}
			if (board[nby][nbx] == '#' || (nby == nry && nbx == nrx))
			{
				nby -= dy[i];
				nbx -= dx[i];
			}

			if (isFailed)
				continue;

			if (board[nry][nrx] == 'O')		//성공 조건
			{
				cout << count + 1;
				return 0;
			}

			q.push({ count + 1, nry, nrx, nby, nbx });
		}
	}

	cout << "-1";
}
