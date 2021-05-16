#include <vector>
using namespace std;

int countDivider(int n) {
    int ret = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0)
            ++ret;
    }
    return ret;
}

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; ++i) {
        answer += countDivider(i) % 2 ? -i : i;
    }
    return answer;
}
