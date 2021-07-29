#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
    int a;
    while (n) {
        a = n % 3;
        n /= 3;
        if (a == 0) n -= 1;
        answer = "412"[a] + answer;
    }
    return answer;
}
