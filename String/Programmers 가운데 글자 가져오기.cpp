#include <string>
using namespace std;

string solution(string s) {
    return s.size() % 2 ? s.substr(s.size() / 2, 1) : s.substr(s.size() / 2 - 1, 2);
}
