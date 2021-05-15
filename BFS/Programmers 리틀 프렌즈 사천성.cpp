#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Direction {
    Direction(int top, int bottom, int left, int right, int count):
        top{top}, bottom{bottom}, left{left}, right{right}, count{count} {}
    int top, bottom, left, right, count;
};

string solution(int m, int n, vector<string> board) {
    vector<vector<pair<int, int>>> tiles(26);
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (isalpha(board[i][j]))
                tiles[board[i][j] - 'A'].push_back({j, i});

    string answer = "";
    for (int i=0; i<26; i++)
    {
        if (tiles[i].empty())
            continue;

        char startAlpha = i + 'A';
        int startX = tiles[i][0].first;
        int startY = tiles[i][0].second;
        int goalX = tiles[i][1].first;
        int goalY = tiles[i][1].second;
        queue<pair<pair<int, int>, Direction>> q;
        q.push({tiles[i][0], {0, 0, 0, 0, 0}});
        while (!q.empty())
        {
            pair<int, int> p = q.front().first;
            Direction d = q.front().second;
            q.pop();
            int x = p.first;
            int y = p.second;
            char alpha = board[p.second][p.first];

            if (d.count > 2)
                continue;

            if ((goalX == x && goalY == y) && startAlpha == alpha)
            {
                board[y][x] = '.';
                board[startY][startX] = '.';
                answer += alpha;
                tiles[i] = vector<pair<int, int>>();
                i = -1;
                break;
            }

            if (board[y][x] != '.' && board[y][x] != startAlpha)
                continue;

            if (d.left == 0 && x < n - 1)
            {
                Direction nextD = {0, 0, 0, 1, d.count};
                if (!d.right)
                    nextD.count++;
                q.push({{x + 1, y}, nextD});
            }
            if (d.right == 0 && x > 0)
            {
                Direction nextD = {0, 0, 1, 0, d.count};
                if (!d.left)
                    nextD.count++;
                q.push({{x - 1, y}, nextD}); 
            }           
            if (d.bottom == 0 && y > 0)
            {
                Direction nextD = {1, 0, 0, 0, d.count};
                if (!d.top)
                    nextD.count++;
                q.push({{x, y - 1}, nextD});
            }
            if (d.top == 0 && y < m - 1)
            {
                Direction nextD = {0, 1, 0, 0, d.count};
                if (!d.bottom)
                    nextD.count++;
                q.push({{x, y + 1}, nextD});
            }
        }
    }

    bool isEmpty = true;
    for (int i=0; i<26; i++)
        if (!tiles[i].empty())
            isEmpty = false;

    if (isEmpty)
        return answer;
    return "IMPOSSIBLE";
}
