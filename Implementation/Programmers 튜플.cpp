#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int> & a, vector<int> & b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> save;
    for (int i = 1; i < s.size() - 1; ++i) {
        vector<int> tmp;
        if (s[i] == '{') {
            ++i;
            while (s[i] != '}') {
                if (s[i] == ',')
                    i++;
                
                string number = "";
                while (s[i] >= 48 && s[i] <= 57)
                    number += s[i++];
                tmp.push_back(stoi(number));
            }
        }
        
        save.push_back(tmp);
    }

    sort(save.begin(), save.end(), cmp);
    
    int check[100001] = { 0 };
    for (int i = 0; i < save.size(); ++i) {
        for (int j = 0; j < save[i].size(); ++j) {
            if (check[save[i][j]] == 0) {
                answer.push_back(save[i][j]);
                check[save[i][j]]++;
            }
        }
    }
    
    return answer;
}
