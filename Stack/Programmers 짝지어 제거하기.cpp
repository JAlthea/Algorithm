#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> sc;
    for (int i=0; i<s.size(); i++)
        if (!sc.empty() && sc.top() == s[i])
            sc.pop();
        else
            sc.push(s[i]);
    return sc.empty() ? 1 : 0;
}
