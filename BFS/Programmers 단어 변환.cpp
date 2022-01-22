#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    bool check = false;
    for (string i : words)
        if (i.find(target) != string::npos) 
            check = true;

    if (!check)
        return 0;
    
    queue<pair<string, int>> q;
    q.push({ begin, 0 });

    while (!q.empty()) {
        pair<string, int> p = q.front(); q.pop();
        if (p.first.find(target) != string::npos) 
            return p.second;
        
        for (int i = 0; i < words.size(); ++i) {
            string now = words[i];
            int count = 0;
            
            for (int j = 0; j < now.size(); ++j)
                if (p.first[j] == now[j])
                    ++count;
            
            if (count == now.size() - 1)
                q.push({ now, p.second + 1 });
        }
    }
    
    return 0;
}