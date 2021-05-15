#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;

	if (s[0] == '0')
	{
		cout << 0;
		return 0;
	}

	string ans = "";
	for (int i = 0; i < s.size(); ++i)
	{
		int t = s[i] - '0';
		string ret = "";
		while (t)
		{
			ret += to_string(t % 2);
			t /= 2;
		}
		reverse(ret.begin(), ret.end());
		while (i && ret.size() < 3) ret = '0' + ret;
		ans += ret;
	}

	cout << ans;
}
