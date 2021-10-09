#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a) {
    int answer = a.size();
    stack<int> s;
    
    for (int i = 0; i < a.size(); ++i) {
        while (!s.empty() && s.top() > a[i]) {
            s.pop();
            if (!s.empty())
                --answer;
        }
        
        s.push(a[i]);
    }
    
    return answer;
}
