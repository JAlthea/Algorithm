#include <string>
using namespace std;

string solution(string s) {
    string t = "";
    int k = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            k = 0;
            t += s[i];
            continue;
        }
        
        if (!k) {
            if (s[i] > 96) t += s[i] - 32;
            else t += s[i];
        }
        else {
            if (s[i] > 64 && s[i] < 91) t += s[i] + 32;
            else t += s[i];
        }
        
        ++k;
    }
    
    return t;
}
