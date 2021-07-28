#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<string> data) {
    int answer = 0;
    char friends[8] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    do {
        bool check = true;
        for (int i = 0; i < data.size(); ++i) {
            string s = data[i];
            int a, b;
            int count = 0;
            for (int j = 0; count < 2; ++j) {
                if (friends[j] == s[0]) a = j, count++;
                else if (friends[j] == s[2]) b = j, count++;
            }
            
            if (s[3] == '=' && abs(a - b) != 1 + s[4] - 48) check = false;
            else if (s[3] == '>' && abs(a - b) <= 1 + s[4] - 48) check = false;
            else if (s[3] == '<' && abs(a - b) >= 1 + s[4] - 48) check = false;

            if (!check) break;
        }
        if (check) answer++;
    } while (next_permutation(friends, friends + 8));

    return answer;
}
