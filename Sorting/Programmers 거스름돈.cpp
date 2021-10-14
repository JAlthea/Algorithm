#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> money) {
    int d[100001] = { 1 , 0 };
    sort(money.begin(), money.end());
    
    for (int i = 0; i < money.size(); ++i) {
        for (int j = money[i]; j <= n; ++j) {	
            d[j] += d[j - money[i]];
            if (d[j] > 1000000006)
                d[j] %= 1000000007;
        }
    }
    
    return d[n] %= 1000000007;
}
