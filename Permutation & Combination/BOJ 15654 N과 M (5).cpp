#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
int check[10001];

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
        if (check[v[i]])
            continue;
        
        check[v[i]]++;
        result.push_back(v[i]);
        f(result, depth + 1);
        result.pop_back();
        check[v[i]]--;
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
