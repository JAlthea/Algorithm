#include <string>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string answer2 = "";
    
    //Step. 1
    transform(begin(new_id), end(new_id), begin(new_id), ::tolower);
    
    //Step. 2
    for (int i = 0; i < new_id.size(); ++i) {
        if (new_id[i] >= 'a' && new_id[i] <= 'z') {
            answer += new_id[i];
        } else if (new_id[i] >= '0' && new_id[i] <= '9') {
            answer += new_id[i];
        } else if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') {
            answer += new_id[i];
        } 
    }
    
    //Step. 3
    for (int i = 0; i < answer.size(); ++i) {
        answer2 += answer[i];
        if (answer[i] == '.') {
            while (i < answer.size() && answer[i] == '.') {
                ++i;
            }
            --i;
        }
    }
    
    //Step. 4
    if (answer2.front() == '.') {
        answer2 = answer2.substr(1);
    }
    if (answer2.back() == '.') {
        answer2.pop_back();
    }
    
    //Step. 5
    if (answer2.empty()) {
        answer2 = "a";
    }

    //Step. 6
    if (answer2.size() >= 16) {
        answer2 = answer2.substr(0, 15);
        if (answer2.back() == '.') {
            answer2.pop_back();
        }
    }
    
    //Step. 7
    if (answer2.size() <= 2) {
        while (answer2.size() != 3) {
            answer2 += answer2.back();
        }
    }
    
    return answer2;
}
