#include <bits/stdc++.h>
using namespace std;

struct hashFunction {
    size_t operator()(const vector<int> &a) const {
        return a[0] * a[2] + a[1] * a[3];
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int l, n;
	cin >> l >> n;
	vector<pair<int, int>> info(n + 1);
	int time;
	char path = 'L';
	for (int i = 0; i < n; i++)
	{
		cin >> time >> path;
		info[i].first = time;
		info[i].second = path;
	}
	info[n].first = 2 * l + 1;
	info[n].second = path;

	unordered_set<vector<int>, hashFunction> body;    //두 점을 잇는 직선 형태로 저장
	const int width = l;
	const int height = width;
	const int dy[] = { 0, -1, 0, 1 };
	const int dx[] = { 1, 0, -1, 0 };
	const int RIGHT = 0;
	const int TOP = 1;
	const int LEFT = 2;
	const int BOTTOM = 3;
	int d = RIGHT, y = 0, x = 0;
	long long t = 0;    //방향, Y, X, 시간
	for (int i = 0; i < n + 1; i++)
	{
		int time = info[i].first;
		int path = info[i].second;
		int ny = y + dy[d] * time;
		int nx = x + dx[d] * time;

		bool isBreak = false;
		long long minTime = LLONG_MAX;
		for (auto &p : body)	//방향 전환 전에 몸통에 부딪히는 경우
		{
			int ax = min(p[0], p[2]);
			int ay = min(p[1], p[3]);
			int bx = max(p[0], p[2]);
			int by = max(p[1], p[3]);

			//자기자신이 포함된 직선 제외
			if (ax == x && ay == y)
				continue;
			if (bx == x && by == y)
				continue;
				
			//현재 x, y에서 진행방향에 있는 두 직선 사이를 살펴야 한다.
			if (ax == bx)
			{
				if (((x <= ax && ax <= nx) && (ay <= y && y <= by)) || ((x >= ax && ax >= nx) && (ay <= y && y <= by)))
				{
					minTime = min(minTime, t + abs(ax - x));
					isBreak = true;
				}
				else if (((x <= ax && ax <= nx) && (y <= ay && ay <= ny)) || ((x >= ax && ax >= nx) && (y <= ay && ay <= ny)))
				{
					minTime = min(minTime, t + abs(ay - y));
					isBreak = true;
				}
			}
			if (ay == by)
			{
				if (((y <= ay && ay <= ny) && (ax <= x && x <= bx)) || ((y >= ay && ay >= ny) && (ax <= x && x <= bx)))
				{
					minTime = min(minTime, t + abs(ay - y));
					isBreak = true;
				}
				else if (((y <= ay && ay <= ny) && (x <= ax && ax <= nx)) || ((y >= ay && ay >= ny) && (x <= ax && ax <= nx)))
				{
					minTime = min(minTime, t + abs(ax - x));
					isBreak = true;
				}
			}
		}
		if (isBreak)
		{
			cout << minTime;
			return 0;
		}

		if (ny < -height || nx < -width || ny > height || nx > width)    //방향 전환 전에 벽에 부딪히는 경우
		{
			if (d == RIGHT)
			{
				cout << t + 1 + width - x;
				return 0;
			}
			else if (d == TOP)
			{
				cout << t + 1 + abs(-height - y);
				return 0;
			}
			else if (d == LEFT)
			{
				cout << t + 1 + abs(-width - x);
				return 0;
			}
			else if (d == BOTTOM)
			{
				cout << t + 1 + height - y;
				return 0;
			}
		}

		body.insert({ x, y, nx, ny });
		t += time;
		y = ny;
		x = nx;
		if (path == 'L')
			d == 3 ? d = 0 : d++;
		else if (path == 'R')
			d == 0 ? d = 3 : d--;
	}
}
