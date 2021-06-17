#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a[5] = { 1, 2, 3, 4, 5 };
    int b[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int c[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    int s[3] = { 0 };
    int d[3] = { 0 };

    for (int i = 0; i < answers.size(); ++i) {
        if (a[i % 5] == answers[i]) s[0]++, d[0]++;
        if (b[i % 8] == answers[i]) s[1]++, d[1]++;
        if (c[i % 10] == answers[i]) s[2]++, d[2]++;
    }

    sort(s, s + 3);
    int max = s[2];

    for (int i = 2; i >= 0; --i) {
        if (d[i] == max) answer.push_back(i+1);
    }

    sort(answer.begin(), answer.end());
    return answer;
}
