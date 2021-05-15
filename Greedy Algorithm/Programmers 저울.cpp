#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> weight) {
    sort(weight.begin(), weight.end());
    int sum = 0;
    for (auto &w : weight)
    {
        if (sum + 1 < w)
            break;
        sum += w;
    }
    return sum + 1;
}
