#import <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, string> &a, pair<int, string> &b)
{
    int A = 0;
    int B = 0;
    string tmp = "";
    for (int i = 0; i < a.second.size(); i++)
    {
        if (a.second[i] == ' ')
            break;

        if (isdigit(a.second[i]))
        tmp += a.second[i];
    }
    A = stoi(tmp);
    
    tmp = "";
    for (int i = 0; i < b.second.size(); i++)
    {
        if (b.second[i] == ' ')
            break;

        if (isdigit(b.second[i]))
            tmp += b.second[i];
    }
    B = stoi(tmp);

    if (A != B)
        return A < B;

    return a.first < b.first;
}

int main()
{
    int n;
    vector<pair<int, string>> v;
    
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string age, name;
        cin >> age >> name;
        
        pair<int, string> tmp;
        tmp.first = i;
        tmp.second = age + " " + name;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<v.size(); i++)
        cout << v[i].second << "\n";
}
