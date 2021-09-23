#include <bits/stdc++.h>
using namespace std;

int answer = 0;
int checkUserID[8] = { 0 };
vector<string> userID;
vector<string> bannedID;
vector<vector<string>> idList;

bool mapping(string & a, string & b) {
    if (a.size() != b.size())
        return false;
    
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i] && b[i] != '*')
            return false;
    
    return true;
}

void dfs(int index, vector<string> save) {
    if (index == bannedID.size()) {
        sort(save.begin(), save.end());
        
        for (int i = 0; i < idList.size(); ++i) {
            bool isSame = true;
            for (int j = 0; j < idList[i].size(); ++j)
                if (save[j] != idList[i][j])
                    isSame = false;
            
            if (isSame)
                return;
        }
        
        ++answer;
        idList.push_back(save);
        return;
    }
    
    for (int i = 0; i < userID.size(); ++i) {
        if (checkUserID[i] == 0 && mapping(userID[i], bannedID[index])) {
            save.push_back(userID[i]);
            ++checkUserID[i];
            dfs(index + 1, save);
            save.pop_back();
            checkUserID[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    userID = user_id;
    bannedID = banned_id;
    vector<string> save;
    dfs(0, save);
    return answer;
}
