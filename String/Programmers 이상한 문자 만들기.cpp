#include <string>
using namespace std;

string solution(string s) {
    for (int i = 0, k = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            k = 0;
            continue;
        }
        
        if (k % 2 == 0 && s[i] > 96) {
            s[i] -= 32;
        }
        else if (s[i] > 64 && s[i] < 97) {
            s[i] += 32;
        }
        
        k++;
    }
    
    return s;
}
