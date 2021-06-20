#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int d[201] = { 0 };
    for (int i=0; i<numbers.size(); ++i) {
        for (int j=0; j<numbers.size(); ++j) {
            if (i == j || d[numbers[i] + numbers[j]])
                continue;
            
            d[numbers[i] + numbers[j]]++;
        }
    }
    
    for (int i=0; i<201; ++i)
        if (d[i])
            answer.push_back(i);
    
    return answer;
}
