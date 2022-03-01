#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string save = "0";

void nextNumbers(vector<string> &v, int index, int count, string now) {
    if (index == count) {  
        save += now;
        return;
    }
    
    for (int i = 0; i < v.size(); ++i) {
        if (index == 0 && i == 0)
            continue;
        
        nextNumbers(v, index + 1, count, now + v[i]);
    }
}

string solution(int n, int t, int m, int p) {
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        if (i > 9)
            v[i] = "ABCDEF"[i - 10];
        else
            v[i] = to_string(i);
    }
    
    for (int i = 1; save.size() <= t * m; ++i)
        nextNumbers(v, 0, i, "");

    string answer = "";
    for (int i = p - 1; answer.size() < t; ++i) {
        answer += save[i];
        i += m - 1;
    }
    
    return answer;
}
