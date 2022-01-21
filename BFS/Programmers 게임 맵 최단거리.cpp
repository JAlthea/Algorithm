#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) {
    int n = maps.size() - 1; 
    int m = maps[0].size() - 1;
    int count = 0;
    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first;
        int y = p.second;

        if (maps[x][y] == 0)
            continue;
        maps[x][y] = 0;

        if (x == n && y == m)
            return count;

        if (x > 0 && maps[x - 1][y] == 1) 
            q.push({ x - 1, y });
        if (y > 0 && maps[x][y - 1] == 1) 
            q.push({ x, y - 1 });
        if (x < n && maps[x + 1][y] == 1) 
            q.push({ x + 1, y });
        if (y < m && maps[x][y + 1] == 1) 
            q.push({ x, y + 1 });
        
        ++count;
    }

    return -1;
}