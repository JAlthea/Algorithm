#include <bits/stdc++.h>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    answer = number.substr(k);
    for (int i = k - 1; i >= 0; --i) {
        int j = 0;
        do {
            if (number[i] < answer[j])
                break;
          
            char temp = answer[j];
            answer[j] = number[i];
            number[i] = temp;
            ++j;

            if (answer.size() <= j)
                cout << answer[j] << "\n";
            else
                cout << j << '\n';
        } while (answer[j]);
    }
 
    return answer;
}
