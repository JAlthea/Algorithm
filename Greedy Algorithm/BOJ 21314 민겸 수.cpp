#include <bits/stdc++.h>
using namespace std;

char s[3001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;

	for (int i = 0; s[i]; ++i) {
		if ('M' == s[i]) {
			int j = i + 1;
			while (s[j]) {
				if ('K' == s[j]) {
					++j;
					break;
				}

				++j;
			}

			--j;

			if ('K' == s[j]) {
				cout << 5;
				for (int x = 0; x < j - i; ++x) {
					cout << 0;
				}
			}
			else {
				cout << 1;
				for (int x = 0; x < j - i; ++x) {
					cout << 1;
				}
			}

			i = j;
		}
		else {
			cout << 5;
		}
	}

	cout << '\n';

	for (int i = 0; s[i]; ++i) {
		if ('M' == s[i]) {
			int j = i + 1;
			while (s[j]) {
				if ('K' == s[j])
					break;

				++j;
			}

			--j;

			cout << 1;
			for (int x = 0; x < j - i; ++x) {
				cout << 0;
			}

			i = j;
		}
		else {
			cout << 5;
		}
	}
}
