#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
bool d[10001];

void f(vector<int> &result, int depth)
{
    if (depth == M)
    {
        for (auto &i : result)
            cout << i << ' ';
        cout << '\n';
        return;
    }
    
    for (int i=0; i<N; i++)
    {
        if (!result.empty() && result.back() > v[i])    //오름차순을 위함
            continue;
        if (d[v[i]])
            continue;
        
        d[v[i]] = true;
        result.push_back(v[i]);
        f(result, depth + 1);
        result.pop_back();
        d[v[i]] = false;
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
    f(result, 0);
}
