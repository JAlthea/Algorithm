#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    if (n % 3 == 1) s = "00" + s;
    else if (n % 3 == 2) s = "0" + s;
    for (int i=0; i<s.size(); i+=3)
        cout << (s[i] - 48) * 4 + (s[i + 1] - 48) * 2 + (s[i + 2] - 48);
}
