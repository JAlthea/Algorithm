#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
const int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    
    while (t--) {
        int length, startY, startX, goalY, goalX;
        cin >> length >> startY >> startX >> goalY >> goalX;
        
        vector<vector<bool>> board(length, vector<bool>(length));
        queue<vector<int>> q;
        q.push({ startY, startX, 0 });
        board[startY][startX] = true;
        
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int y = p[0];
            int x = p[1];
            int count = p[2];
            
            if (y == goalY && x == goalX) {
                cout << count << '\n';
                break;
            }
            
            for (int i = 0; i < 8; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if (ny < 0 || nx < 0 || ny >= length || nx >= length) 
                    continue;
                
                if (board[ny][nx])
                    continue;
                
                board[ny][nx] = true;
                q.push({ ny, nx, count + 1 });
            }
        }
    }
}
