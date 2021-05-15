#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

bool cmp2(vector<int> a, vector<int> b)
{
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end(), cmp2); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    vector<pair<int, int>> s;
    for (int i=0, k=0, sup=0; s.size() < jobs.size(); i++, sup--)
    {
        while (k < jobs.size() && i == jobs[k][0])
        {
            pq.push({jobs[k][0], jobs[k][1]});    
            k++;
        }
        
        if (sup <= 0 && !pq.empty())
        {
            sup = pq.top().second;
            s.push_back(pq.top());
            pq.pop();
        }
    }
    
    int answer = 0;
    int delay = 0;
    for (int i=0; i<s.size(); i++)
    {
        if (delay <= s[i].first)
        {
            answer += s[i].second;
            delay += s[i].first - delay + s[i].second;
        }
        else
        {
            answer += delay - s[i].first + s[i].second;
            delay += s[i].second;
        }
    }
    
    return answer / s.size();
}
