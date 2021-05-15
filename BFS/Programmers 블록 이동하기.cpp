#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct hashFunction {
    size_t operator()(const vector<int> &a) const {
        int resultA = 0;
        int digit = 1;
        for (int i=0; i<4; i++)
        {
            resultA += a[i] * digit;
            digit *= 10;
        }
        return resultA;
    }
};

int solution(vector<vector<int>> board) {
    const int N = board.size() - 1;
    const int dy[] = { 0, 1, -1, 0 };
    const int dx[] = { 1, 0, 0, -1 };
    int answer = 0;
    unordered_set<vector<int>, hashFunction> checkBoard;    //좌표 중복체크를 위함
    
    queue<vector<int>> q;
    q.push({0, 0, 0, 0, 1});    // { 시간, Y1좌표, X1좌표, Y2좌표, X2좌표 }
    while (!q.empty())
    {
        vector<int> v = q.front(); q.pop();
        int time = v[0];
        int y1 = min(v[1], v[3]);
        int x1 = min(v[2], v[4]);
        int y2 = max(v[1], v[3]);
        int x2 = max(v[2], v[4]);
        
        if (y1 == N && x1 == N)
            return time;
        if (y2 == N && x2 == N)
            return time;
        
        vector<int> tmpObject {y1, x1, y2, x2};
        if (checkBoard.find(tmpObject) != checkBoard.end())
            continue;
        checkBoard.insert(move(tmpObject));
        
        for (int i=0; i<4; i++) //로봇의 4방향 이동
        {
            int ny1 = y1 + dy[i];
            int nx1 = x1 + dx[i];
            int ny2 = y2 + dy[i];
            int nx2 = x2 + dx[i];
            
            if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0)
                continue;
            if (ny1 > N || nx1 > N || ny2 > N || nx2 > N)
                continue;
            if (board[ny1][nx1] == 1 || board[ny2][nx2] == 1)
                continue;
            
            q.push({time + 1, ny1, nx1, ny2, nx2});
        }
        
        if (y1 == y2)   //로봇이 수평으로 놓여있는 경우의 회전
        {
            int ry1[] = {1, -1, 0, 0};
            int rx1[] = {1, 1, 0, 0};
            int ry2[] = {0, 0, -1, 1};
            int rx2[] = {0, 0, -1, -1};
            int cy1[] = {1, -1, 0, 0};
            int cx1[] = {0, 0, 0, 0};
            int cy2[] = {0, 0, -1, 1};
            int cx2[] = {0, 0, 0, 0};
            for (int i=0; i<4; i++)
            {
                //다음 좌표
                int ny1 = y1 + ry1[i];
                int nx1 = x1 + rx1[i];
                int ny2 = y2 + ry2[i];
                int nx2 = x2 + rx2[i];
                
                //회전 시 검사용 좌표
                int my1 = y1 + cy1[i];
                int mx1 = x1 + cx1[i];
                int my2 = y2 + cy2[i];
                int mx2 = x2 + cx2[i];
                
                if (my1 < 0 || mx1 < 0 || my2 < 0 || mx2 < 0)
                    continue;
                if (my1 > N || mx1 > N || my2 > N || mx2 > N)
                    continue;
                if (board[my1][mx1] == 1 || board[my2][mx2] == 1)
                    continue;
                if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0)
                    continue;
                if (ny1 > N || nx1 > N || ny2 > N || nx2 > N)
                    continue;
                if (board[ny1][nx1] == 1 || board[ny2][nx2] == 1)
                    continue;
                
                q.push({time + 1, ny1, nx1, ny2, nx2});
            }
        }
        
        if (x1 == x2)   //로봇이 수직으로 놓여있는 경우의 회전
        {
            int ry1[] = {1, 1, 0, 0};
            int rx1[] = {1, -1, 0, 0};
            int ry2[] = {0, 0, -1, -1};
            int rx2[] = {0, 0, 1, -1};
            int cy1[] = {0, 0, 0, 0};
            int cx1[] = {1, -1, 0, 0};
            int cy2[] = {0, 0, 0, 0};
            int cx2[] = {0, 0, 1, -1};
            for (int i=0; i<4; i++)
            {
                //다음 좌표
                int ny1 = y1 + ry1[i];
                int nx1 = x1 + rx1[i];
                int ny2 = y2 + ry2[i];
                int nx2 = x2 + rx2[i];
                
                //회전 시 검사용 좌표
                int my1 = y1 + cy1[i];
                int mx1 = x1 + cx1[i];
                int my2 = y2 + cy2[i];
                int mx2 = x2 + cx2[i];                
                
                if (my1 < 0 || mx1 < 0 || my2 < 0 || mx2 < 0)
                    continue;
                if (my1 > N || mx1 > N || my2 > N || mx2 > N)
                    continue;
                if (board[my1][mx1] == 1 || board[my2][mx2] == 1)
                    continue;
                if (ny1 < 0 || nx1 < 0 || ny2 < 0 || nx2 < 0)
                    continue;
                if (ny1 > N || nx1 > N || ny2 > N || nx2 > N)
                    continue;
                if (board[ny1][nx1] == 1 || board[ny2][nx2] == 1)
                    continue;
                
                q.push({time + 1, ny1, nx1, ny2, nx2});
            }            
        }
    }
    
    return -1;
}
