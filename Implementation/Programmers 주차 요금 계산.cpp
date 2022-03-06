#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char deli) {
    istringstream ss(s);
    vector<string> result;
    string nowString;
  
    while (getline(ss, nowString, deli))
        result.push_back(nowString);
  
    return result;
}

int timeToInt(const string &stringTimeFormat) {
    vector<string> s = split(stringTimeFormat, ':');
    if (s.empty()) 
        return -1;
    
    // hh
    if (s.size() == 1) 
        return stoi(s[0]);
    
    // hh:mm
    if (s.size() == 2) 
        return 60 * stoi(s[0]) + stoi(s[1]);
    
    // hh:mm:ss
    if (s.size() == 3) 
        return 3600 * stoi(s[0]) + 60 * stoi(s[1]) + stoi(s[2]);
    
    // not supported
    return -1;
}

int getTotalFee(const vector<int> &fees, int countedTime) {
    if (countedTime < fees[0])
        return fees[1];
    
    return fees[1] + ceil((double)(countedTime - fees[0]) / fees[2]) * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> carNumberAndTotalFee;    // { carNumber, totalFee }
    map<string, int> nowTimes;    // { carNumber, nowTime }
    map<string, int> countedTimes;    // { carNumber, totalTime }
    map<string, bool> lastOrders;    // { carNumber, in | out }
    
    for (int i = 0; i < records.size(); ++i) {
        vector<string> s = split(records[i], ' ');
        
        if (s[2] == "IN") {
            nowTimes[s[1]] = timeToInt(s[0]);
            lastOrders[s[1]] = true;
        }
        else {
            countedTimes[s[1]] += timeToInt(s[0]) - nowTimes[s[1]];
            lastOrders[s[1]] = false;
        }
    }
    
    for (const auto &i : nowTimes) {
        if (lastOrders[i.first]) {
            countedTimes[i.first] += 1439 - i.second;
        }
        
        carNumberAndTotalFee[i.first] = getTotalFee(fees, countedTimes[i.first]);
    }
    
    vector<pair<string, int>> tmp(carNumberAndTotalFee.begin(), carNumberAndTotalFee.end());
    sort(tmp.begin(), tmp.end());
    for (const auto &i : tmp) {
        answer.push_back(i.second);
    }
    
    return answer;
}
