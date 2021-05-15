#include <bits/stdc++.h>
using namespace std;

const unsigned R = 31;
const unsigned M = 1234567891;

unsigned hashFunction(string & s) {
	unsigned long long ret = 0;
	unsigned long long R_pow = 1;
	for (unsigned i = 0; i < s.size(); ++i) {
		ret += (s[i] - 96) * R_pow % M;
		R_pow = R_pow * R % M;
	}

	return ret % M;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int l;
	string s;
	cin >> l >> s;
	cout << hashFunction(s);
}
