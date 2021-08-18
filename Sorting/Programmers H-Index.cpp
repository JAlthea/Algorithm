#include <vector>
#include <algorithm>
using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), desc);
    
    if (citations[citations.size() - 1] >= citations.size())
        return citations.size();
    
    int answer = citations[citations.size() - 1];
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i) {
            answer = i;
            break;
        }
    }
    
    if (answer > citations[0])
        answer = citations[0];
    
    int count = 0;
    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < answer)
            break;
        ++count;
    }
    
    while (count < answer)
        answer--;
    
    /*
    int count = 0;
    answer++;
    do {
        count = 0;
        --answer;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] < answer)
                break;
            ++count;
        } 
    } while (count < answer);
    */

    return answer;
}
