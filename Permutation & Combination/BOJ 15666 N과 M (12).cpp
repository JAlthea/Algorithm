#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
set<vector<int>> check;

void f(vector<int> &result, int depth, int index)
{
    if (depth == M)
    {
        if (check.find(result) != check.end())
            return;
        check.emplace(result);
        
        for (auto &i : result)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=index; i<N; i++)
    {
        result.push_back(v[i]);
        f(result, depth + 1, i);
        result.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    v.resize(N);
    for (int i=0; i<N; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    
    vector<int> result;
    f(result, 0, 0);
}
