#include <bits/stdc++.h>
using namespace std;

string getGrade(double now_aver) {
    if (now_aver == 0)
        return "F";
    
    switch ((int) now_aver / 10) {
        case 10:
        case 9:
            return "A";
        case 8:
            return "B";
        case 7:
            return "C";
        case 6:
        case 5:
            return "D";
        default:
            return "F";
    }
}

string solution(vector<vector<int>> scores) {
    string answer = "";
    for (int j = 0; j < scores.size(); ++j) {
        double now_aver = -1;
        int now_sum = 0;
        int now_max_score = -1;
        int now_max_index = -1;
        int now_min_score = 101;
        int now_min_index = -1;
        
        for (int i = 0; i < scores.size(); ++i) {
            int now_score = scores[i][j];
            now_sum += now_score;
            
            if (now_max_score <= now_score) {
                if (now_max_score == now_score) 
                    now_max_index = -1;
                else
                    now_max_index = i;
                
                now_max_score = now_score;
            }
            if (now_min_score >= now_score) {
                if (now_min_score == now_score) 
                    now_min_index = -1;
                else
                    now_min_index = i;
                
                now_min_score = now_score;
            }
        }
        
        if (now_sum == 0) {
            now_aver = 0;
        }
        else if (now_max_index == j) {
            now_sum -= now_max_score;
            now_aver = (double) now_sum / (scores.size() - 1);
        }
        else if (now_min_index == j) {
            now_sum -= now_min_score;
            now_aver = (double) now_sum / (scores.size() - 1);
        }
        else {
            now_aver = (double) now_sum / scores.size();
        }
        
        answer += getGrade(now_aver);
    }
    
    return answer;
}
