#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, e;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i)
    {
        cin >> s >> e;
        if (s > e) arr.push_back({ e, s });
    }
    
    sort(arr.begin(), arr.end());
    
    long long ret = m;
    int left = arr[0].first;
    int right = arr[0].second;
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i].first > right)
        {
            ret += (right - left) * 2;
            left = arr[i].first;
            right = arr[i].second;
        }
        else if (arr[i].second > right)
        {
            right = arr[i].second;
        }
    }
    
    cout << ret + (right - left) * 2;
}
