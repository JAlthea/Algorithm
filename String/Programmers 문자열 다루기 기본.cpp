#include <string>
using namespace std;

bool solution(string s) {
    for (char & c : s) {
        if (c < 47 || c > 58) {
            return false;
        }
    }
    return s.size() != 4 && s.size() != 6 ? false : true;
}
