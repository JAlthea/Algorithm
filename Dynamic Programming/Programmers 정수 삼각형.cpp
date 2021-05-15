#include <vector>
using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> tmp = triangle;
    for (int i=tmp.size() - 1; i>0; i--)
        for (int j=0; j<tmp[i].size() - 1; j++)
            tmp[i-1][j] += tmp[i][j] > tmp[i][j+1] ? tmp[i][j] : tmp[i][j+1];
    return tmp[0][0];
}
