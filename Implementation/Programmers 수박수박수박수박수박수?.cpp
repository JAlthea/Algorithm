#include <string>
using namespace std;

string solution(int n) {
    string s = "";
    for (int i = 0; i < n; ++i)
        s += i & 1 ? "박" : "수";
    return s;
}
