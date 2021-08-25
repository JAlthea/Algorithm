#include <bits/stdc++.h>
using namespace std;

vector<string> split(string & s, char deli) {
    istringstream ss(s);
    vector<string> result;
    string nowString;
    while (getline(ss, nowString, deli))
        result.push_back(nowString);
    return result;
}

bool cmp(pair<string, int> & a, pair<string, int> & b) {
    if (a.second == b.second)
        return a < b;
    return a.second > b.second;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
    map<string, int> language_preference;
    vector<pair<string, int>> company_score(5);
    
    for (int i = 0; i < languages.size(); ++i) {
        language_preference[languages[i]] = preference[i];
    }
    
    for (int i = 0; i < table.size(); ++i) {
        vector<string> s = split(table[i], ' ');
        string company = s[0];
        int score = 0;
        for (int j = 1; j < 6; ++j) {
            if (language_preference.find(s[j]) == language_preference.end())
                continue;
            
            score += language_preference[s[j]] * (6 - j);
        }
        
        company_score[i] = { company, score };
    }
    
    sort(company_score.begin(), company_score.end(), cmp);
    
    return company_score.front().first;
}
