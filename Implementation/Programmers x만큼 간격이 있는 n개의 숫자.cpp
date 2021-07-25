#include <vector>
using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    long long i = x;
    while (n--) {
        answer.push_back(i);
        i += x;
    }
    return answer;
}
