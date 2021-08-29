#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Song {
    string name;
    int time;
    int index;
};

bool cmp(Song & a, Song & b) {
    if (a.time == b.time)
        return a.index < b.index;
    return a.time > b.time;
}

string solution(string m, vector<string> musicinfos) {
    string word = "";
    for (int i = 0; m[i]; ++i) {
        if (m[i + 1] && m[i + 1] == '#')
            word += m[i++] - 17;
        else
            word += m[i];
    }
    
    vector<Song> songs;
    for (int i = 0; i < musicinfos.size(); ++i) {
        string s = musicinfos[i];
        int hour = ((s[6] - 48) * 10 + (s[7] - 48)) - ((s[0] - 48) * 10 + (s[1] - 48));
        int minute = ((s[9] - 48) * 10 + (s[10] - 48)) - ((s[3] - 48) * 10 + (s[4] - 48));
        int time = hour * 60 + minute;
        
        int k = 12;
        string name = "";
        while (s[k] != ',')
            name += s[k++];
        ++k;
        
        string info = "";
        while (s[k]) {
            if (s[k + 1] && s[k + 1] == '#') {
                info += s[k] - 17;
                k += 2;
                continue;
            }
            
            info += s[k++];
        }

        int oneRaps = info.size();
        string playedInfo = "";
        for (int j = 0, k = 0; j < time; ++j) {
            if (k == oneRaps)
                k = 0;
            playedInfo += info[k++];
        }

        if (playedInfo.find(word, 0) != string::npos)
            songs.push_back({ name, time, i });
    }
    
    if (songs.size() == 0)
        return "(None)";
    return (*min_element(songs.begin(), songs.end(), cmp)).name;
}
