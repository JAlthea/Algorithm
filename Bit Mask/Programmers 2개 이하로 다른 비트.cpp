#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
    if (n % 2 == 0)
        return n + 1;
    
    long long ret;
    long long pow2k = 1;
    while (1) {
        if ((n ^ pow2k) == n + pow2k) {
            ret = (n | pow2k) ^ (pow2k / 2);
            break;
        }
        pow2k *= 2;
    }

    return ret;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer(numbers.size());
    for (int i = 0; i < numbers.size(); ++i) {
        answer[i] = f(numbers[i]);
    }
    return answer;
}
