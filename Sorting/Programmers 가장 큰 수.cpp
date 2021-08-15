#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool desc(string & a, string & b) {
    string tmpA = a;
    string tmpB = b;
    
    while (tmpA > tmpB && tmpA.size() > tmpB.size())
        tmpB += tmpB[0];
    while (tmpA < tmpB && tmpA.size() < tmpB.size())
        tmpA += tmpA[0];
    
    if (tmpA == tmpB && a != b) {
        if (a.size() < b.size())
            return tmpB[1] > tmpB[2];
        if (a.size() > b.size())
            return tmpA[1] < tmpA[2];
    }

    return tmpA > tmpB;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> save;
    
    for (int i = 0; i < numbers.size(); ++i)
        save.push_back(to_string(numbers[i]));
    
    sort(save.begin(), save.end(), desc);
    
    for (int i = 0; i < numbers.size(); ++i)
        answer += save[i];   
  
    return save[0] == "0" ? "0" : answer;
}
