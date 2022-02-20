#import <bits/stdc++.h>
using namespace std;

int n, i = 666, k = 1;

bool check(const string &s) {
    int a = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (a == 3)
            return true;
        s[i] == '6' ? ++a : a = 0;
    }
	
    if (a == 3)
	return true;
    return false;
}

int main() {
    cin >> n;
	
    while (k < n) {
        ++i;
        if (check(to_string(i)))
            ++k;
    }

    cout << i;
}
