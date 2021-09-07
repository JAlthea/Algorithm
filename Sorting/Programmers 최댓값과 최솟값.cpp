#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> v;
    
    string tmp = "";
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            v.push_back(stoi(tmp));
            tmp = "";
            continue;
        }   
        
        tmp += s[i];
    }
    v.push_back(stoi(tmp));
     
    return to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));
}
