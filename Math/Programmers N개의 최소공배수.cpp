#include <vector>
using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    for (int i = 0; i < arr.size(); ++i)
        answer = lcm(answer, arr[i]);
    return answer;
}
