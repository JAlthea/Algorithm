#include <string>
#include <vector>
#include <set>
using namespace std;

bool isPossibleXY(set<pair<int, int>> &s, vector<vector<int>> &board) {
    int minX = 1e9;
    int minY = 1e9;
    int maxX = -1;
    int maxY = -1;
    for (auto &i : s)
    {
        if (minX > i.first)
            minX = i.first;
        if (minY > i.second)
            minY = i.second;
        if (maxX < i.first)
            maxX = i.first;
        if (maxY < i.second)
            maxY = i.second;
    }

    for (int i=minX; i<=maxX; i++)
    {
        for (int j=minY; j<=maxY; j++)
        {
            if (s.find({i, j}) != s.end())
                continue;

            for (int k=0; k<=i; k++)
                if (board[k][j] > 0)
                    return false;
        }  
    }

    return true;
}

int solution(vector<vector<int>> board) {
    vector<set<pair<int, int>>> v(201);
    for (int i=0; i<board.size(); i++)
        for (int j=0; j<board.size(); j++)
            if (board[i][j])
                v[board[i][j]].insert({i, j});

    int answer = 0;
    for (int i=1; i<201; i++)
    {
        set<pair<int, int>> s = v[i];
        if (s.empty())
            continue;
        if (!isPossibleXY(s, board))
            continue;

        answer++;
        v[i] = set<pair<int, int>>();
        for (auto p : s)
            board[p.first][p.second] = 0;
        i = 0;
    }

    return answer;
}
