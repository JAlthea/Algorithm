#include <bits/stdc++.h>
using namespace std;

int l, c;
unordered_set<char> checkV, checkC;

void BF(vector<char> &arr, vector<char> &ret, int index)
{
    if (ret.size() == l && !checkV.empty() && checkC.size() >= 2)
    {   
        for (auto &i : ret) cout << i;
        cout << '\n';
        return;
    }
    
    if (index == arr.size()) return;
    
    for (int i=index; i<arr.size(); ++i)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u') 
            checkV.insert(arr[i]);
        else 
            checkC.insert(arr[i]);
        
        ret.push_back(arr[i]);
        BF(arr, ret, i + 1);
        ret.pop_back();
        
        if (checkV.find(arr[i]) != checkV.end()) 
            checkV.erase(arr[i]);
        else 
            checkC.erase(arr[i]);
    }
}

int main()
{
    cin >> l >> c;
    vector<char> arr(c), ret;
    for (int i=0; i<c; ++i)
        cin >> arr[i];
    
    sort(arr.begin(), arr.end());
    BF(arr, ret, 0);
}
