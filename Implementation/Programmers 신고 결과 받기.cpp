#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s, char deli) {
    istringstream ss(s);
    vector<string> result;
    string nowString;
    while (getline(ss, nowString, deli))
        result.push_back(nowString);
    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    map<string, int> counted_report;
    map<string, int> indexed_report;
    set<pair<string, string>> checked_report;
    
    for (int i = 0; i < id_list.size(); ++i) {
        indexed_report[id_list[i]] = i;
    }
    
    for (int i = 0; i < report.size(); ++i) {
        vector<string> s = split(report[i], ' ');
        
        if (checked_report.find({ s[0], s[1] }) == checked_report.end()) {
            checked_report.insert({ s[0], s[1] });
            ++counted_report[s[1]];
        }
    }
    
    checked_report.clear();
    for (int i = 0; i < report.size(); ++i) {
        vector<string> s = split(report[i], ' ');
        
        if (checked_report.find({ s[0], s[1] }) != checked_report.end()) 
            continue;
        checked_report.insert({ s[0], s[1] });
        
        if (counted_report[s[1]] >= k) {
            ++answer[indexed_report[s[0]]];
        }
    }
    
    return answer;
}
