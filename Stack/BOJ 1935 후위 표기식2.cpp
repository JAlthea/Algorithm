#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t; string s;
    cin >> n >> s;
    unordered_map<char, double> m;
    for (int i=0, j=0; i<n; ++i)
    {
        while (!isalpha(s[j]) || m.find(s[j]) != m.end()) j++;
        cin >> t;
        m[s[j++]] = t;
    }

    stack<double> st;
    for (int i=0; i<s.size(); ++i)
    {
        if (isalpha(s[i])) st.push(m[s[i]]);
        else
        {
            double a = st.top(); st.pop();
            double b = st.top(); st.pop();
            if (s[i] == '*') st.push(b * a);
            else if (s[i] == '/') st.push(b / a);
            else if (s[i] == '+') st.push(b + a);
            else if (s[i] == '-') st.push(b - a);
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << st.top();
}
