#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    set<string> type;
    map<string, int> match;
    
    for (int i = 0; i < clothes.size(); ++i) {
        if (type.count(clothes[i][1])) {
            match[clothes[i][1]]++;
            continue;
        }
        
        type.insert(clothes[i][1]);
        match.insert({ clothes[i][1], 1 });
    }

    for (auto i = match.begin(); i != match.end(); i++)
        answer *= (i->second + 1);
    
    return answer - 1;
}
