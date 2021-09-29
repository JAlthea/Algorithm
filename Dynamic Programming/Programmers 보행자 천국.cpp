#include <vector>
using namespace std;

struct Value {
    int left = 0;
    int top = 0;
    int total = 0;
};

void isGreater(Value &value, int MOD) {
    if (value.left >= MOD)
        value.left %= MOD;
    if (value.top >= MOD)
        value.top %= MOD;
    if (value.total >= MOD)
        value.total %= MOD;
}

Value zeroValue() {
    Value c;
    return c;
}

Value oneValue() {
    Value c;
    c.left = 1;
    c.top = 1;
    c.total = 1;
    return c;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    int MOD = 20170805;
    vector<vector<Value>> map(city_map.size(), vector<Value>(city_map[0].size()));
    map[0][0] = oneValue();
    
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            if (i == 0 && j == 0)
                continue;

            if (city_map[i][j] == 1) {
                map[i][j] = zeroValue();
                continue;
            }
            
            map[i][j] = zeroValue();
            if (i > 0) {
                if (city_map[i - 1][j] == 2)
                    map[i][j].top = map[i - 1][j].top;
                else
                    map[i][j].top = map[i - 1][j].total;           
            }
            if (j > 0) {
                if (city_map[i][j - 1] == 2)
                    map[i][j].left = map[i][j - 1].left;
                else
                    map[i][j].left = map[i][j - 1].total;                
            }

            map[i][j].total = map[i][j].left + map[i][j].top;
            isGreater(map[i][j], MOD);
        }
    }

    return map[map.size() - 1][map[0].size() - 1].total;
}
