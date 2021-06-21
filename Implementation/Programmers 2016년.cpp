#include <string>
using namespace std;

string solution(int a, int b) {
    const string d[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    for (int i = a - 1; i > 0; --i) {
        if (i == 2) b += 29;
        else if (i == 4 || i == 6 || i == 9 || i == 11) b += 30;
        else b += 31;
    }
    return d[(b - 1) % 7];
}
