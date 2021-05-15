#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    return a.second > b.second;
}

bool cmp2(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, vector<pair<int, int>>> m;
    unordered_map<string, int> genre;
    for (int i=0; i<plays.size(); i++)
    {
        if (m.find(genres[i]) == m.end())
            genre.insert({genres[i], 0});
        genre[genres[i]] += plays[i];
        m[genres[i]].push_back({i, plays[i]});
    }
    for (auto i=m.begin(); i !=m.end(); i++)
        sort((i->second).begin(), (i->second).end(), cmp2);

    vector<pair<string, int>> v(genre.begin(), genre.end());
    sort(v.begin(), v.end(), cmp);
    vector<int> answer;
    for (int i=0; i<v.size(); i++)
    {
        string nowGenre = v[i].first;
        for (int j=0; j<m[nowGenre].size(); j++)
        {
            answer.push_back(m[nowGenre][j].first);
            if (j == 1)
                break;
        }
    }
    return answer;
}
