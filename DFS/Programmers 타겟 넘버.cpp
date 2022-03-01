#include <string>
#include <vector>
using namespace std;

int count;

void dfs(vector<int> &v, int index, int now, int target) {
    if (index == v.size()) {
        if (now == target)
            ++count;
        return;
    }
    
    dfs(v, index + 1, now + v[index], target);
    dfs(v, index + 1, now - v[index], target);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, 0, 0, target);
    return count;
}
