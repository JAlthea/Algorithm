#include <vector>
#include <algorithm>
using namespace std;

int d[100000][4];
int solution(vector<vector<int>> land) {
    for (int i = 0; i < 4; ++i)
        d[0][i] = land[0][i];
    
    for (int i = 1; i < land.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            int nowMax = 0;
            for (int k = 0; k < 4; ++k) {
                if (k == j)
                    continue;
                nowMax = max(nowMax, d[i - 1][k]);
            }
            d[i][j] = nowMax + land[i][j];
        }    
    }
    
    return *max_element(d[land.size() - 1], d[land.size() - 1] + 4);
}
