#include <bits/stdc++.h>
using namespace std;

int convertTimeNumber(int number) {
    int timeNumber = number;
  
    if (timeNumber > 9999) {
        string tmp = to_string(timeNumber);
        for (int i = tmp.size() - 5; i >= 0; i -= 2)
            tmp[i] = min(tmp[i], '5');
      
        timeNumber = stoi(tmp);
    }
  
    return timeNumber;
}

string countDigit(string result, int index) {
    if (result[index] == '6') {
        result[index] = '0';
        if (index == 0) {
            result = '1' + result;
            return result;
        }

        if (result[index - 1] == '9') {
            result[index - 1] = '0';
            if (index - 1 == 0) {
                result = '1' + result;
                return result;
            }
            
            if (result[index - 2] == '5') {
                result[index - 2] = '0';
                if (index - 2 == 0) {
                    result = '1' + result;
                    return result;
                }
                
                result[index - 3]++;
                return result;
            }
            else {
                result[index - 2]++;
                return result;
            }
        }
        else {
            result[index - 1]++;
            return result;
        }
    }
    
    return result;
}

int convertTimeNumber2(int number) {
    int timeNumber = number;
  
    if (timeNumber > 9999) {
        string tmp = to_string(timeNumber);
        if (tmp[tmp.size() - 5] == '6')
            tmp = countDigit(tmp, tmp.size() - 5);
      
        timeNumber = stoi(tmp);
    }
    
    return timeNumber;
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<vector<int>> edgePoints;
  
    for (int i = 0; i < lines.size(); ++i) {
        string line = lines[i];
        int index = 11;
        string S = "";
        while (line[index] != ' ') {
            if (line[index] >= '0' && line[index] <= '9')
                S += line[index];
            ++index;
        }
      
        ++index;
        string T = "";
        while (line[index] != 's') {
            if (line[index] >= '0' && line[index] <= '9')
                T += line[index];
            ++index;
        }
      
        while (T.size() < 4)
            T += '0';
        
        int endPoint = stoi(S);
        int startPoint = endPoint - stoi(T) + 1;
        startPoint = convertTimeNumber(startPoint);
        edgePoints.push_back({ startPoint, endPoint, i });
    }
    
    for (int i = 0; i < edgePoints.size(); ++i) {
        for (int a = 0; a < 2; ++a) {
            int start = edgePoints[i][a];
            int maxPoint = convertTimeNumber2(start + 999);
            int checkIndex[2001] = { 0 };
            int count = 0;
            for (int k = 0; k < edgePoints.size(); ++k) {
                if (edgePoints[k][0] > maxPoint || edgePoints[k][1] < start)
                    continue;
                
                if (checkIndex[edgePoints[k][2]] == 0) {
                    ++checkIndex[edgePoints[k][2]];
                    ++count;
                }
            }
            
            answer = max(answer, count);
        }
    }

    return answer;
}
