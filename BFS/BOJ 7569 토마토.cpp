#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, h, remainCount = 0, count = 0, timeCount = 0;
    cin >> m >> n >> h;
    vector<vector<vector<int>>> board(h, vector<vector<int>>(n, vector<int>(m, 0)));
    vector<vector<vector<bool>>> checkedBoard(h, vector<vector<bool>>(n, vector<bool>(m, false)));
    queue<vector<int>> q;    //{ z, y, x, time }
    for (int i=0; i<h; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            for (int k=0; k<m; ++k)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                    q.push({ i, j, k, 0 });
                else if (board[i][j][k] == 0)
                    remainCount++;
            }
        }
    }
    
    if (remainCount == 0)
    {
        cout << 0;
        return 0;
    }
    
    const int dz[] = { 0, 0, 0, 0, 1, -1 };
    const int dy[] = { 1, -1, 0, 0, 0, 0 };
    const int dx[] = { 0, 0, 1, -1, 0, 0 };
    while (!q.empty())
    {
        vector<int> v = q.front(); q.pop();
        int z = v[0];
        int y = v[1];
        int x = v[2];
        int nowTime = v[3];
        
        if (remainCount == count)
            break;
        
        for (int i=0; i<6; ++i)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m)
                continue;
            if (checkedBoard[nz][ny][nx] || board[nz][ny][nx] != 0)
                continue;
            
            checkedBoard[nz][ny][nx] = true;
            board[nz][ny][nx] = 1;
            count++;
            timeCount = max(timeCount, nowTime + 1);
            q.push({ nz, ny, nx, nowTime + 1 });
        }
    }
    
    cout << (remainCount == count ? timeCount : -1);
}
