#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    int result[201][201] = { { 0 } };
    int d[202] = { 0 };
    d[0] = matrix_sizes[0][0];
    
    for (int i = 1; i <= matrix_sizes.size(); ++i)
        d[i] = matrix_sizes[i - 1][1];
    
    for (int i = 2; i <= matrix_sizes.size(); ++i) {  //size까지 부분행렬의곱을 확장 : AB -> ABC -> ABCD ...
        for (int j = 1; j <= matrix_sizes.size() - i + 1; ++j) {  //계산에 필요한 모든 인접한 행렬의 곱 : AB, BC, CD, ... , ABC, BCD, CDE, ...
            int k = j + i - 1;
            result[j][k] = 1e9;
            
            for (int n = j; n < k; ++n)
                result[j][k] = min(result[j][k], result[j][n] + result[n + 1][k] + d[j - 1] * d[n] * d[k]);
        }
    }
    
    return result[1][matrix_sizes.size()];
}
