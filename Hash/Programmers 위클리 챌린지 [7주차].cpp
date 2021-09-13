#include <bits/stdc++.h>
using namespace std;

int enterMap[1001], leaveMap[1001];

bool isMeet(vector<int> & enter, vector<int> & leave, int p, int q) {
    int a = enter[p], b = enter[q];

    for (int i = 0; i < leave.size(); ++i) {
        if (leave[i] == a) {
            break;
        }
        if (leave[i] == b) {
            return true;
        }
    }

    for (int i = 0; i < leave.size(); ++i) {
        if (leave[i] == a || leave[i] == b)
            continue;

        if (enterMap[leave[i]] > q && leaveMap[leave[i]] < leaveMap[a])
            return true;
    }

    return false;
}

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer(enter.size());

    for (int i = 0; i < enter.size(); ++i) {
        enterMap[enter[i]] = i;
        leaveMap[leave[i]] = i;
    }

    for (int i = 0; i < enter.size(); ++i) {
        for (int j = i + 1; j < enter.size(); ++j) {
            if (isMeet(enter, leave, i, j)) {
                ++answer[enter[i] - 1];
                ++answer[enter[j] - 1];
            }
        }
    }

    return answer;
}

//1. a번과 b번의 순서가 역순이 있을 때, 예: (1, 2) (2, 1)
//2. a번과 b번 이후에 들어온 c번이 퇴실 순서로 a번 보다 앞에 있을 때, 예: (1, 4, 2) (2, 1, 4)
