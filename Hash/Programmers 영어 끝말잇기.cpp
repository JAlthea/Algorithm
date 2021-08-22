#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;
    
    string now = words[0];
    s.insert(words[0]);
    for (int i = 1; i < words.size(); ++i) {
        if (now.back() != words[i].front()) {
            answer.push_back(i % n + 1);
            answer.push_back(ceil((double)(i + 1) / n));
            return answer;
        }
        else {
            if (s.end() != s.find(words[i])) {
                answer.push_back(i % n + 1);
                answer.push_back(ceil((double)(i + 1) / n));
                return answer;
            }
            
            s.insert(words[i]);
            now = words[i];
        }
    }

    return { 0, 0 };
}
