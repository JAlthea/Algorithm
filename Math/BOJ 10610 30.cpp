#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int nSum = 0;
	for (auto &i : s) nSum += i - '0';
	sort(s.begin(), s.end(), greater<>());
	if (s.back() == '0' && nSum % 3 == 0) for (auto &i : s) cout << i;
	else cout << -1;
}
