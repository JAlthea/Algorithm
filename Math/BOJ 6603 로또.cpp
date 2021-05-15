#include <bits/stdc++.h>
using namespace std;

void backTracking(vector<int> &arr, vector<int> &ret, int index)
{
    if (ret.size() == 6)
    {
        for (auto &c : ret) cout << c << ' ';
        cout << '\n';
        return;
    }
    
    if (index == arr.size()) return;
    
    for (int i=index; i<arr.size(); ++i)
    {
        ret.push_back(arr[i]);
        backTracking(arr, ret, i + 1);
        ret.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int k;
    while (cin >> k)
    {
        if (k == 0) break;
        
        vector<int> arr(k), ret;
        for (int i=0; i<k; ++i)
            cin >> arr[i];

        backTracking(arr, ret, 0);
        cout << '\n';
    }
}
