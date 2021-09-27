#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0, maxH = 0;
    
    for (int i = 0; i < sizes.size(); ++i) {
        int w = sizes[i][0];
        int h = sizes[i][1];
        if (w > h) swap(w, h);
        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }
    
    return maxW * maxH;
}
