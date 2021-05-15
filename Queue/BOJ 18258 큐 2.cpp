#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    queue<int> q;
    while(n--)
    {
        int value;
        string s;
        cin >> s;
        if(s[0] == 'p' && s[1] == 'u')
        {
            cin >> value;
            q.push(value);
        }
        else if(s[0] == 'f')
            cout << (q.empty() ? -1 : q.front()) << '\n';
        else if(s[0] == 'b')
            cout << (q.empty() ? -1 : q.back()) << '\n';
        else if(s[0] == 's')
            cout << q.size() << '\n';
        else if(s[0] == 'e')
            cout << q.empty() << '\n';
        else
        {
            if(q.empty())
                cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
                q.pop();
            }
        }
    }
}
