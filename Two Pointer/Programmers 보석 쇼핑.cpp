#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2);
    unordered_map<string, int> m;
    set<string> s;
    int n = gems.size();
    for (int i=0; i<n; ++i)
        s.insert(gems[i]);

    int allGemSize = s.size();
    int minStart = 0;
    int minEnd = INT_MAX;
    int start = 0;
    int end = 0;
    for (int i=0; i<n; ++i)
    {
        m[gems[end++]]++;
        while (m[gems[start]] >= 2)
            m[gems[start++]]--;
        
        if (m.size() >= allGemSize && minEnd - minStart > end - start - 1)
        {
            minStart = start + 1;
            minEnd = end;
        }
    }
    
    answer.front() = minStart;
    answer.back() = minEnd;
    return answer;
}
