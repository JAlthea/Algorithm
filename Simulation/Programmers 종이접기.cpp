#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    n--;
    while (n--)
    {
        vector<int> sub = answer;
        sub[sub.size() / 2] = 1;
        answer.push_back(0);
        for (int i=0; i<sub.size(); i++)
            answer.push_back(sub[i]);
    } 
    return answer;
}
