#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k, l;
	cin >> n >> k;

	//사과의 위치 정보
	set<vector<int>> apple;
	for (int i = 0; i < k; i++)
	{
		int y, x;
		cin >> y >> x;
		apple.insert({ y - 1, x - 1 });
	}

	//뱀의 방향 변환 정보
	cin >> l;
	vector<pair<int, int>> info;    //'D' => 오른쪽, 'L' => 왼쪽
	for (int i = 0; i < l; i++)
	{
		int time;
		char d;
		cin >> time;
		cin >> d;
		info.push_back({ time, d });
	}

	const int LEFT = 0;
	const int TOP = 1;
	const int RIGHT = 2;
	const int BOTTOM = 3;
	int dy[] = { 0, -1, 0, 1 };
	int dx[] = { -1, 0, 1, 0 };
	set<vector<int>> bodyCheck;    //뱀의 몸통 체크
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;	//위치 정보 최신화
	bodyCheck.insert({ 0, 0 });
	pq.push({ 0, 0, 0 });
	int time = 0;
	int y = 0;
	int x = 0;
	int d = RIGHT;
	int ny = 0;
	int nx = 0;
	int tailY = 0;
	int tailX = 0;
	int index = 0;
	while (1)
	{
		ny = y + dy[d];
		nx = x + dx[d];
		time++;

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)    //벽에 부딪히거나
		{
			cout << time;
			break;
		}
		if (bodyCheck.find({ ny, nx }) != bodyCheck.end())    //몸통에 부딪히거나
		{
			cout << time;
			break;
		}

		if (apple.find({ ny, nx }) != apple.end())    //사과가 있다면
		{
			bodyCheck.insert({ ny, nx });
			pq.push({ time, ny, nx });
			apple.erase({ ny, nx });    //먹은 사과 제거
		}
		else    //사과가 없다면
		{
			bodyCheck.insert({ ny, nx });
			bodyCheck.erase({ tailY, tailX }); //꼬리 제거
			pq.push({ time, ny, nx });
			pq.pop();
			if (!pq.empty())
			{
				tailY = pq.top()[1];
				tailX = pq.top()[2];
			}
			else
			{
				tailY = ny;
				tailX = nx;
			}
		}

		if (index < l)
		{
			int t = info[index].first;
			char path = info[index].second;
			if (t == time)
			{
				if (path == 'D')
				{
					d = (d + 1) % 4;
				}
				else if (path == 'L')
				{
					if (d == 0)
						d = 3;
					else
						d--;
				}

				index++;
			}
		}

		y = ny;
		x = nx;
	}
}
