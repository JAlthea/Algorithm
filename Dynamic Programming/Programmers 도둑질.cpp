#include <bits/stdc++.h>
using namespace std;

vector<int> m;
int d[1000001][2], size;
bool choiceStart;

int stealing(int n)
{
    if(size - 1 == n)
    {
        if(choiceStart)
            return 0;
        else
            return m[n];
    }

    if(size - 1 < n)
        return 0;

    if(d[n][choiceStart] != -1)
        return d[n][choiceStart];

    int ret = 0;
    ret = max(ret, stealing(n + 2) + m[n]);
    ret = max(ret, stealing(n + 1));
    return d[n][choiceStart] = ret;
}

int solution(vector<int> money)
{
    size = money.size();
    m = money;
    memset(d, -1, sizeof(d));

    int answer = 0;
    choiceStart = true;
    answer = max(answer, stealing(2) + m[0]);
    choiceStart = false;
    answer = max(answer, stealing(1));

    return answer;
}
