/*
//Solution1
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = n;
    int i = 0;
    int fir = 0;
    int a = 0, b = -1, cnt = 0;

    while (1) {
        if (n % 2) {
            if (cnt == 0)
                fir = i;
            ++cnt;
        }
        else {
            if (b == 1) {
                answer += pow(2, fir) + pow(2, cnt - 1) - 1;
                break;
            }
            ++i;
        }
        
        b = a;
        n /= 2;
    }

    return answer;
}
*/

//Solution2
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getCntNum(int n) {
    int nCnt = 0;
    for (int i = 0; i < 31; ++i)
        if (n & 0x01 << i)
            ++nCnt;
    return nCnt;
}

int solution(int n) {
    int nNumCnt = getCntNum(n);
    while (1) {
        ++n;
        if (nNum1Cnt == getCntNum(n))
            return n;
    }
}
