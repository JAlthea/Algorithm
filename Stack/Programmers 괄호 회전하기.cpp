#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    deque<char> d;
    for (auto & c : s)
        d.push_back(c);
    
    int answer = 0;
    for (int i = 0; i < s.size(); ++i) {
        bool isRight = true;
        stack<char> st;
        for (auto & c : d) {
            if (c == '(' || c == '[' || c == '{') 
                st.push(c);
            else {
                if (st.empty()) {
                    isRight = false;
                    break;
                }
                int cmpC = st.top();
                if (c == ')' && cmpC == '(') st.pop();
                else if (c == ']' && cmpC == '[') st.pop();
                else if (c == '}' && cmpC == '{') st.pop();
                else {
                    isRight = false;
                    break;
                }
            }
        }
        
        if (!st.empty())
            isRight = false;
        
        if (isRight)
            ++answer;
        
        d.push_back(d.front());
        d.pop_front();
    }
    
    return answer;
}
