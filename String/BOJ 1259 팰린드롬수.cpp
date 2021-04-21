#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    while (cin >> s) {
        if (s == "0") break;
        bool isPalin = true;
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - 1 - i]) {
                isPalin = false;
                break;
            }
        }
        cout << (isPalin ? "yes " : "no ");
    }
}
