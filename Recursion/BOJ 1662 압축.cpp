#include <bits/stdc++.h>
using namespace std;

string s;

pair<int, int> f(int start) {
	pair<int, int> ret = { 0, 2 };
	for (int i = start; i < s.size(); ++i) {
		if ('(' == s[i]) {
			--ret.first;
			auto subRet = f(i + 1);
			ret.first += (s[i - 1] - '0') * subRet.first;
			ret.second += subRet.second;
			i += subRet.second - 1;
		}
		else if (')' == s[i]) {
			return ret;
		}
		else {
			++ret.first;
			++ret.second;
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	cout << f(0).first;
}
