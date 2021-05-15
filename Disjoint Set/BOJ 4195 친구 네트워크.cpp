#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> s;
unordered_map<string, int> h;

string findSet(string &e)
{
	if (s[e] == e) return e;
	return s[e] = findSet(s[e]);
}

void unionSet(string &a, string &b)
{
	a = findSet(a);
	b = findSet(b);
	if (a == b) return;

	if (h[a] < h[b])
	{
		h[b] += h[a];
		s[a] = b;
	}
	else
	{
		h[a] += h[b];
		s[b] = a;
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		s.clear();
		h.clear();
		int f;
		string from, to;
		cin >> f;
		for (int i = 0; i < f; ++i)
		{
			cin >> from >> to;
			if (s.find(from) == s.end()) s[from] = from;
			if (s.find(to) == s.end()) s[to] = to;
			if (h.find(from) == h.end()) h[from] = 1;
			if (h.find(to) == h.end()) h[to] = 1;
			unionSet(from, to);
			cout << max(h[findSet(from)], h[findSet(to)]) << '\n';
		}
	}
}
