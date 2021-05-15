#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 1, -1, 0, 0 };
const int dx[] = { 0, 0, 1, -1 };

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, k, a, b;
        cin >> m >> n >> k;
        vector<vector<int>> board(n, vector<int>(m, 0));
        for (int i=0; i<k; ++i)
        {
            cin >> a >> b;
            board[b][a]++;
        }
        
        int minCount = 0;
        vector<vector<bool>> checkedBoard(n, vector<bool>(m, false));
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                if (checkedBoard[i][j] || board[i][j] == 0)
                    continue;
                
                checkedBoard[i][j] = true;
                minCount++;
                queue<pair<int, int>> q;
                q.push({ i, j });
                while (!q.empty())
                {
                    pair<int, int> p = q.front(); q.pop();
                    int y = p.first;
                    int x = p.second;
                    
                    for (int k=0; k<4; ++k)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= m)
                            continue;
                        
                        if (checkedBoard[ny][nx] || board[ny][nx] == 0)
                            continue;
                        
                        checkedBoard[ny][nx] = true;
                        q.push({ ny, nx });
                    }
                }
            }
        }
        
        cout << minCount << '\n';
    }
}
