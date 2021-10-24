#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int wordBackTracking(vector<string> & words, int index) {
    if (words.front() == words.back())
        return index;
    
    vector<string> filteredWords;
    int plus = 0;
    int sum = 0;
    char nextStart = words[0][index];
    
    for (int i = 0; i < words.size(); ++i) {
        if (!words[i][index]) {
            sum += index;
            continue;
        }

        if (nextStart == words[i][index]) {
            if (!words[i][index + 1]) {
                sum += index + 1;
                plus = 1;
            }
            else
                filteredWords.push_back(words[i]);
        }
        else {
            nextStart = words[i][index];
            if (!filteredWords.empty())
                sum += wordBackTracking(filteredWords, index + 1 + plus);
            
            plus = 0;
            filteredWords = vector<string>();
            --i;
        }
    }
    
    if (!filteredWords.empty())
        sum += wordBackTracking(filteredWords, index + 1 + plus);
    
    return sum;
}

int solution(vector<string> words) {
    sort(words.begin(), words.end());
    return wordBackTracking(words, 0);
}
