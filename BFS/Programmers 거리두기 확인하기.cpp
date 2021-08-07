#include <string>
#include <vector>
#include <queue>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(5);

    for (int k = 0; k < places.size(); ++k) {
        bool isKeepDistance = true;
        bool visited[5][5] = { { 0 } };
        
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (places[k][i][j] != 'P' || visited[i][j])
                    continue;

                visited[i][j] = true;
                queue<vector<int>> q;
                q.push({ i, j, 0 });
                while (!q.empty()) {
                    auto p = q.front(); q.pop();
                    int y = p[0];
                    int x = p[1];
                    int count = p[2];
                    
                    if (count && places[k][y][x] == 'P') {
                        isKeepDistance = false;
                        goto endForLoop;
                    }
                    
                    if (count == 2)
                        continue;
                    
                    for (int r = 0; r < 4; ++r) {
                        int ny = y + dy[r];
                        int nx = x + dx[r];
                        
                        if (ny < 0 || nx < 0 || ny > 4 || nx > 4)
                            continue;
                        
                        if (places[k][ny][nx] == 'X' || visited[ny][nx])
                            continue;
                        
                        visited[ny][nx] = true;
                        q.push({ ny, nx, count + 1 });
                    }
                }
            }
        }
        
        endForLoop:
        if (isKeepDistance)
            answer[k]++; 
    }
    
    return answer;
}
