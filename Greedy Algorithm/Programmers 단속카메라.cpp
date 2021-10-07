#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int result = 1;
    int endPoint = routes[0][1];
    
    for (int i = 1; i < routes.size(); ++i) {
        if (endPoint < routes[i][0]) {
            ++result;
            endPoint = routes[i][1];
        }
        
        if (endPoint > routes[i][1])
            endPoint = routes[i][1];
    }
    
    return result;
}
