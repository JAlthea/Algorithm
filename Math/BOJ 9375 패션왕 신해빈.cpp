#include <bits/stdc++.h>
using namespace std;

int t, n;
int main()
{
    for(cin >> t; t--;)
    {
        cin >> n;
        map<string, int> m;
        string s;
        while(n--)
            cin >> s >> s, m.find(s) == m.end() ? m[s] = 1 : ++m[s];
        n = 1;
        for(auto i=m.begin(); i!=m.end(); ++i)
            n *= 1 + (*i).second;
        cout << n - 1 << ' ';
    }
}
