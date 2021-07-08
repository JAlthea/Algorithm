#include <string>
using namespace std;

string solution(string s, int n) {
    string answer = s;

    for (unsigned short i = 0; i < s.size(); ++i) {
        if (s[i] == ' ')
            continue;
        
        int tmp = static_cast<int>(s[i]) + n;
        
        s[i] += n;
        if (tmp > 122 || (tmp > 90 && s[i] <= 90))
            s[i] -= 26;
    }
    
    return answer;
}
