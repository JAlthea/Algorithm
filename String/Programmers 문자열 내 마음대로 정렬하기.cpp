#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer(strings.size());
    
    for (int i = 0; i < strings.size(); ++i) {
        string tmp = strings[i][n] + strings[i];
        strings[i].replace(0, strings[i].size(), tmp);
    }
    
    sort(strings.begin(), strings.end());
    
    for (int i = 0; i < strings.size(); ++i) {
        answer[i] = strings[i].substr(1);
    }
    
    return answer;
}
