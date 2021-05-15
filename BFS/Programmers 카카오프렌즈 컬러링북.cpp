#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Point {
    int x;
    int y;
    int value;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    const int dy[] = { 1, 0, -1, 0 };
    const int dx[] = { 0, 1, 0, -1 };
    vector<vector<char>> visited(m, vector<char>(n, 0));
    vector<int> area;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (visited[i][j] || !picture[i][j])
                continue;
            
            queue<Point> q;
            q.push({j, i, picture[i][j]});
            int count = 0;
            while (!q.empty())
            {
                Point p = q.front(); q.pop();
                
                if (visited[p.y][p.x])
                    continue;
                visited[p.y][p.x]++;
                count++;
                
                for (int i=0; i<4; i++)
                {
                    int ny = p.y + dy[i];
                    int nx = p.x + dx[i];
                    if (ny < 0 || nx < 0 || ny >= m || nx >= n)
                        continue;
                    if (picture[ny][nx] == p.value)
                        q.push({nx, ny, p.value});
                }
            }
            
            area.push_back(count);
        }
    }
    
    vector<int> answer(2);
    answer[0] = area.size();
    answer[1] = *max_element(area.begin(), area.end());
    return answer;
}
