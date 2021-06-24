#include <string>
using namespace std;

int solution(string dartResult) {
    int s[3] = { 0 };
    int now = 0;
    for (int i = 0, k = 0; i < dartResult.size(); ++i) {
        if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
            now = 10;
            i++;
        } else if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            now = dartResult[i] - 48;
        } else {
            if (dartResult[i] == 'D') now *= now;
            else if (dartResult[i] == 'T') now *= now * now;
            
            if (dartResult[i + 1] == '*') {
                if (k > 0) s[k - 1] <<= 1;
                s[k] = now << 1;
                i++;
            } else if (dartResult[i + 1] == '#') {
                s[k] = -now;
                i++;
            } else {
                s[k] = now;
            }
            k++;
        }
    }

    return s[0] + s[1] + s[2];
}
