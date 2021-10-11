#include <string>
using namespace std;

int solution(string s) {
    int result = 1;
    
    for (int n = 2; n <= s.size(); ++n) {
        bool check = true;
        
        for (int i = 0; i < s.size(); ++i) {
            check = true;
            if (i + n - 1 >= s.size())
                break;
            
            int k = 0;
            while (k <= n / 2 - 1) {
                if (s[i + k] != s[i + n - 1 - k]) {
                    check = false;
                    break;
                }
                ++k;
            }
            
            if (check) {
                result = n;
                break;
            }
        }
    }
    
    return result;
}
