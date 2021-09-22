#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> times;
    
    for (int i = 0; i < timetable.size(); ++i) {
        string crew = timetable[i];
        int time = ((crew[0] - 48) * 10 * 60) + ((crew[1] - 48) * 60) + ((crew[3] - 48) * 10) + (crew[4] - 48);
        times.push_back(time);
    }
    sort(times.begin(), times.end());

    int con = 0;
    int maxTime = 540 + ((n - 1) * t);
    int startIndex = 0;
    for (int shuttle = 540; shuttle <= maxTime; shuttle += t) {
        int nowM = 0;
        
        for (int i = startIndex; i < times.size(); ++i) {
            if (nowM == m)
                break;
            
            if (shuttle >= times[i])
                ++nowM;
        }
        if (nowM < m)
            con = shuttle;
        else
            con = times[startIndex + m - 1] - 1;
        
        startIndex += nowM;
    }
    
    string hour = to_string(con / 60);
    string minute = to_string(con % 60);
    if (hour.size() == 1)
        hour = '0' + hour;
    if (minute.size() == 1)
        minute = '0' + minute;
    string answer = hour + ':' + minute;
    return answer;
}
