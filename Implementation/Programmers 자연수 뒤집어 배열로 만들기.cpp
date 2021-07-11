#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.size(); ++i)
        answer.push_back(s[i] - 48);
    return answer;
}
