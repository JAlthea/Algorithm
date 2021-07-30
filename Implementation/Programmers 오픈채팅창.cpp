#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    vector<string> saveUser;
    int size = record.size();
    for (int i = 0; i < size; ++i) {
        string s = record[i];
        if (s[0] == 'E') {
            int j = 6;
            string userID = "";
            while (s[j] != ' ')
                userID += s[j++];
            j++;
            string userNick = "";
            while (s[j] && s[j] != ' ')
                userNick += s[j++];
            m[userID] = userNick;
            saveUser.push_back(userID);
            answer.push_back("님이 들어왔습니다.");
        }
        else if (s[0] == 'L') {
            int j = 6;
            string userID = "";
            while (s[j] && s[j] != ' ')
                userID += s[j++];
            saveUser.push_back(userID);
            answer.push_back("님이 나갔습니다.");
        }
        else {
            int j = 7;
            string userID = "";
            while (s[j] != ' ')
                userID += s[j++];
            j++;
            string userNick = "";
            while (s[j] && s[j] != ' ')
                userNick += s[j++];
            m[userID] = userNick;
        }
    }
    
    int resultSize = saveUser.size();
    vector<string> result(resultSize);
    for (int i = 0; i < resultSize; ++i)
        result[i] = m[saveUser[i]] + answer[i];
    return result;
}
