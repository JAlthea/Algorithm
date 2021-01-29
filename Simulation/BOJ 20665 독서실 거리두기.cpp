#include <bits/stdc++.h>
using namespace std;

set<int> checkedS;
vector<pair<string, string>> reserved;
vector<pair<string, string>> times;
int n, t, p;

int checkChair()
{
	int maxDist = -1;
	int prevS = 0, endS = n + 1;
	int left = 0, right = 0;
	for (auto &s : checkedS)
	{
		if ((s - prevS) / 2 > maxDist)
		{
			left = prevS;
			right = s;
			maxDist = (s - prevS) / 2;
			if (prevS == 0) maxDist = s - 1;	//1번의 경우
		}
		prevS = s;
	}
	if (endS - 1 - prevS > maxDist)	//N번의 경우
	{
		left = prevS;
		right = endS;
	}

	if (left == 0)
	{
		checkedS.insert(1);
		return 1;
	}
	if (right == n + 1)
	{
		checkedS.insert(n);
		return n;
	}

	checkedS.insert((left + right) / 2);
	return (left + right) / 2;
}

void checkTimeout(string &time)
{
	for (auto &s : checkedS)
		if (time >= reserved[s].second) reserved[s].second = "-1";

	for (int s = 1; s <= n; ++s)
		if (reserved[s].second == "-1") checkedS.erase(s);
}

int getBetweenTime(string &startTime, string &endTime)
{
	int h = stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0, 2));
	int m = stoi(endTime.substr(2, 2)) - stoi(startTime.substr(2, 2));
	if (m < 0) --h, m += 60;
	return h * 60 + m;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> t >> p;
	reserved.resize(n + 1);
	times.resize(t);
	for (int i = 0; i < t; ++i)
		cin >> times[i].first >> times[i].second;
	sort(times.begin(), times.end());

	int ret = 720;
	for (int i = 0; i < t; ++i)
	{
		checkTimeout(times[i].first);
		int s = checkChair();
		string left = times[i].first;
		string right = times[i].second;
		reserved[s].first = left;
		reserved[s].second = right;
		if (s == p) ret -= getBetweenTime(left, right);
	}

	cout << ret;
}
