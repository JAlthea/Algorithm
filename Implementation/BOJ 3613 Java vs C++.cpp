#include <bits/stdc++.h>
using namespace std;

bool isCamelCase(string s) {
    if (isupper(s.front()))
        return false;
    
    for (auto & c : s)
        if (c == '_')
            return false; 
    
    return true;
}

bool isSnakeCase(string s) {
    if (s.front() == '_' || s.back() == '_')
        return false;
    
    bool isContinue = false;
    for (auto & c : s) {
        if (isupper(c))
            return false;
        
        if (c == '_') {
            if (isContinue)
                return false;
            
            isContinue = true;
        }
        else {
            isContinue = false;
        }
    }
    
    return true;
}

string getSnakeCase(string s) {
    string result = "";
    
    for (int i = 0; i < s.size(); ++i) {
        if (isupper(s[i])) {
            result += '_';
            result += s[i] - 'A' + 'a';
            continue;
        }
        
        result += s[i];
    }
    
    return result;
}

string getCamelCase(string s) {
    string result = "";
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '_') {
            ++i;
            result += s[i] - 'a' + 'A';
            continue;
        }
        
        result += s[i];
    }
    
    return result;
}

int main() {
    string s;
    cin >> s;
    
    if (isCamelCase(s))
        cout << getSnakeCase(s);
    else if (isSnakeCase(s))
        cout << getCamelCase(s);
    else
        cout << "Error!";
}
