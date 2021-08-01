#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check(string src) {
    stack <char> s;
  
    for (int i = 0; i < src.size(); ++i) {
        if (src[i] == '(') {
            s.push(src[i]);
            continue;
        }

        if (s.empty())
            return false;
        s.pop();
    }
  
    if (!s.empty())
        return false;
    return true;
}

string fix(string src) {
    string result = "";
    for (int i = 1; i < src.size() - 1; ++i) {
        if (src[i] == '(') result += ')';
        if (src[i] == ')') result += '(';
    }
    return result;
}

string divide(string src) {   
    if (src == "") return src;
    
    string result = "";
    string u = "";
    string v = "";
    int left = 0;
    int right = 0;
    for (int i = 0; i < src.size(); ++i) {
        u += src[i];
        if (src[i] == '(') left++;
        if (src[i] == ')') right++;
        if (left == right) break;
    }
  
    v = src.substr(u.size());

    if (check(u)) {
        result += u;
        result += divide(v);
    }
    else {
        result += '(';
        result += divide(v);
        result += ')';
        result += fix(u);
    }
    
    return result;
}

string solution(string p) {
    return check(p) ? p : divide(p);
}
