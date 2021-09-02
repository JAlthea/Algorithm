#include <string>
#include <stack>
using namespace std;

bool solution(string s) {
    stack<char> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            v.push(s[i]);
            continue;
        }

        if (v.empty())
            return false;
        v.pop();
    }

    if (!v.empty())
        return false;
    return true;
}
