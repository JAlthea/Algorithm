#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int map[101][101] = { 0 };
    
    for(int i=0; i<puddles.size(); ++i)
        map[puddles[i][1]][puddles[i][0]] = -1;

    map[1][0] = 1;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(map[i][j] < 0)
                map[i][j] = 0;
            else
            {
                map[i][j] = map[i-1][j] + map[i][j-1];
                if (map[i][j] > 1000000006)
                    map[i][j] %= 1000000007;
            }
        }
    }
    
    return map[n][m];
}
