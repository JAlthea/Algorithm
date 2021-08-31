#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> m;
    string alpa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 1; i <= 26; ++i)
        m.insert({ alpa.substr(i - 1, 1), i });
    int nextIndex = 27;
    
    vector<int> answer;
    int size = msg.size();
    for (int i = 0; i < size; ++i) {
        int k = size;
        string s = msg.substr(i, k);
        while (m.find(s) == m.end())
            s = msg.substr(i, --k);
        answer.push_back(m[s]);
        s = msg.substr(i, k + 1);
        m.insert({s, nextIndex++});
        i += k - 1;
    }
    
    return answer;
}
