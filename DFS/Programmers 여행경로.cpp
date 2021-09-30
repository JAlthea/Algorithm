#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> indexs;
vector<vector<string>> results;

bool cmp(vector<string> & a, vector<string> & b) {
    if (a[0] == b[0])
        for (int i = 0; i < a[1].size(); ++i)
            if (a[1][i] != b[1][i])
                return a[1][i] < b[1][i];
    
    for (int i = 0; i < a[0].size(); ++i)
        if (a[0][i] != b[0][i])
            return a[0][i] < b[0][i];
}

void dfs(vector<vector<string>> & v, vector<string> result, string now, int size, int count) {
    for (int i = 0; i < size; ++i) {
        if (!indexs[i] && now == v[i][0]) {
            ++indexs[i];
            result.push_back(v[i][1]);
            dfs(v, result, v[i][1], size, count + 1);
            result.pop_back();
            --indexs[i];
        }
    }
    
    if (count == size + 1)
        results.push_back(result);
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end(), cmp);
    int size = tickets.size();
    indexs.resize(size, 0);
    
    for (int i = 0; i < size; ++i) {
        if (tickets[i][0] != "ICN")
            continue;
        
        vector<string> tmp;
        tmp.push_back(tickets[i][0]);
        dfs(tickets, tmp, tickets[i][0], size, 1);
    }
    
    return *min_element(results.begin(), results.end(), cmp);
}
