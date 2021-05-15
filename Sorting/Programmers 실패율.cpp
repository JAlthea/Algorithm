#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b)
{
    if (a.first == b.first)     //문제의 조건에 따라 비교가 가능하다.
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer(N);
    vector<int> d(N+2, 0);
    int n = stages.size();
    for (int i=0; i<n; i++)
        d[stages[i]]++;
    
    vector<pair<double, int>> v(N, {0, 0});
    int count = 0;
    for (int i=1; i<=N; i++)
    {
        if (d[i] == 0)
            v[i-1].first = 0;
        else
            v[i-1].first = (double)d[i] / (n - count);
        v[i-1].second = i;
        count += d[i];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i=0; i<N; i++)
        answer[i] = v[i].second;
    
    return answer;
}
