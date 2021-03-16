#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
	if (a.second == b.second)
	{
		if (a.first.size() == b.first.size()) return a.first < b.first;
		return a.first.size() > b.first.size();
	}
	return a.second > b.second;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;

	map<string, int> ht;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if (s.size() < m) continue;
		++ht[s];
	}
	
	vector<pair<string, int>> arr(ht.begin(), ht.end());
	sort(arr.begin(), arr.end(), cmp);

	for (auto &s : arr)
		cout << s.first << '\n';
}
