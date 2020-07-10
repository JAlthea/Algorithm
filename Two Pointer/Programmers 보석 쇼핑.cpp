#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> m;
    set<string> s;
    int n = gems.size();
    for (int i=0; i<n; i++)
        s.insert(gems[i]);

    int allGemSize = s.size();
    int minStart = 0;
    int minEnd = (int)1e9;
    int start = 0;
    int end = 0;
    for (int i=0; i<n; i++)
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
    
    answer.push_back(minStart);
    answer.push_back(minEnd);
    return answer;
}
