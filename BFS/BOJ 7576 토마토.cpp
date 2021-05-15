#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, remainCount = 0, count = 0, timeCount = 0;
    cin >> m >> n;
    vector<vector<int>> board(n, vector<int>(m, 0));
    vector<vector<bool>> checkedBoard(n, vector<bool>(m, false));
    queue<vector<int>> q;    //{ y, x, time }
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                q.push({ i, j, 0 });
            else if (board[i][j] == 0)
                remainCount++;
        }
    }
    
    if (remainCount == 0)
    {
        cout << 0;
        return 0;
    }
    
    const int dy[] = { 1, -1, 0, 0 };
    const int dx[] = { 0, 0, 1, -1 };
    while (!q.empty())
    {
        vector<int> v = q.front(); q.pop();
        int y = v[0];
        int x = v[1];
        int nowTime = v[2];
        
        if (remainCount == count)
            break;
        
        for (int i=0; i<4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                continue;
            if (checkedBoard[ny][nx] || board[ny][nx] != 0)
                continue;
            
            checkedBoard[ny][nx] = true;
            board[ny][nx] = 1;
            count++;
            timeCount = max(timeCount, nowTime + 1);
            q.push({ ny, nx, nowTime + 1 });
        }
    }
    
    cout << (remainCount == count ? timeCount : -1);
}
