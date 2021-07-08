#include <string>
using namespace std;

string solution(string s, int n) {
    string answer = s;

    for (unsigned short i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
            continue;
        
        int shift = static_cast<int>(s[i]) + n;
        char c = s[i];
        
        s[i] += n;
        if (shift > 122 || (shift > 90 && c <= 90))
            s[i] -= 26;
    }
    
    return answer;
}
