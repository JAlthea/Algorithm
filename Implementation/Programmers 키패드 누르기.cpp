#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left[2] = { 3, 0 }, right[2] = { 3, 2 };
    for (int i = 0; i < numbers.size(); ++i) {
        int n = numbers[i];
        if (n == 1 || n == 4 || n == 7) {
            answer += "L";
            left = { n / 3, 0 };
        }
        else if (n == 3 || n == 6 || n == 9) {
            answer += "R";
            right = { n / 4, 2 };
        }
        else {
            if (n == 0) n = 11;
            
            int y = n / 3;
            int x = 1;
            int d1 = abs(left[0] - y) + abs(left[1] - x);
            int d2 = abs(right[0] - y) + abs(right[1] - x);
            if (hand == "left") {
                if (d1 == d2 || d1 < d2) {
                    answer += "L";
                    left = { y, x };
                } else {
                    answer += "R";
                    right = { y, x };
                }
            } else {
                if (d1 == d2 || d1 > d2) {
                    answer += "R";
                    right = { y, x };
                } else {
                    answer += "L";
                    left = { y, x };
                }
            }
        }
    }
    
    return answer;
}
