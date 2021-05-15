#import <iostream>
#import <string>
#import <vector>
#import <algorithm>
using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

int main()
{
    int n;
    string s;
    vector<string> v;
    cin >> n;
    while (n--)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);

    s = "*";
    for (int i = 0; i < v.size(); i++)
    {
        if (s == v[i])
            continue;
        s = v[i];
        cout << v[i] << '\n';
    }
}
