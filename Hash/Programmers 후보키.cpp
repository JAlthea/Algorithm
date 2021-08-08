#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<string> usedAttr;

bool checkSubAttr(string s) {
    for (int i = 0; i < usedAttr.size(); ++i) {
        int count = 0;
        for (int j = 0; j < s.size(); ++j) 
            if (usedAttr[i].find(s[j], 0) != string::npos)
                count++;

        if (count == usedAttr[i].size())
            return true;
    }
    return false;
}

int checkDuplication(vector<vector<string>> &relation, int attrCount) {
    int colSize = relation[0].size();
    vector<int> v(colSize, 0);
    for (int i = colSize - 1; i > colSize - 1 - attrCount; --i)
        v[i] = 1;

    int rowSize = relation.size();
    int count = 0;
    do {
        vector<int> save;
        for (int i = 0; i < colSize; ++i)
            if (v[i] == 1)
                save.push_back(i);

        string tmp = "";
        for (int i = 0; i < save.size(); ++i)
            tmp += save[i] + 48;

        if (checkSubAttr(tmp))
            continue;

        for (int i = 0; i < colSize; ++i)
            if (v[i] == 1)
                save.push_back(i);

        set<string> s;
        bool checkDup = false;
        for (int i = 0; i < rowSize; ++i) {
            string nowCol = "";
            for (int j = 0; j < save.size(); ++j)
                nowCol += relation[i][save[j]];

            if (s.find(nowCol) == s.end())
                s.insert(nowCol);
            else {
                checkDup = true;
                break;
            }
        }

        if (checkDup == false) {
            usedAttr.push_back(tmp);
            count++;
        }
    } while (next_permutation(v.begin(), v.end()));

    return count;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    for (int i = 1; i <= relation[0].size(); ++i)
        answer += checkDuplication(relation, i);
    return answer;
}
