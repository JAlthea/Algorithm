#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if (cacheSize == 0)
        return cities.size() * 5;
    
    int answer = 0;
    list<string> l;
    for (int i = 0; i < cities.size(); ++i) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);
        auto p = find(l.begin(), l.end(), cities[i]);
        if (p != l.end()) {
            l.erase(p);
            ++answer;
        }
        else {
            if (l.size() == cacheSize)
                l.pop_front();
            answer += 5;
        }
        
        l.push_back(cities[i]);
    }
    
    return answer;
}
