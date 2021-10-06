#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Info {
    vector<string> links;
    int index;
    int baseScore;
    double linkScore = 0;
    double matcingScore = 0;
};

bool cmp(pair<double, int> & a, pair<double, int> & b) {
    if (fabs(a.first - b.first) < numeric_limits<double>::epsilon())
        return a.second < b.second;
    
    return a.first > b.first;
}

int solution(string word, vector<string> pages) {
    map<string, Info> m;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    for (int i = 0; i < pages.size(); ++i) {
        transform(pages[i].begin(), pages[i].end(), pages[i].begin(), ::tolower);
        string nowPage = pages[i];
        string url = "";
        int baseScore = 0;
        vector<string> links;
        
        /* search url */
        int urlIndexStart = nowPage.find("<meta property=\"og:url") + 33;
        int urlIndexEnd = nowPage.find("\"", urlIndexStart);
        url = nowPage.substr(urlIndexStart, urlIndexEnd - urlIndexStart);
        
        /* search word */
        string searchPage = pages[i];
        int wordIndex = searchPage.find(word);
        while (wordIndex != string::npos) {
            string tmp = searchPage.substr(wordIndex - 1, word.size() + 2);
            if (!isalpha(tmp.front()) && !isalpha(tmp.back()))
                ++baseScore;
            searchPage = searchPage.substr(wordIndex + 1);
            wordIndex = searchPage.find(word);
        }
        
        /* search links */
        while (nowPage.find("<a href") != string::npos) {
            nowPage = nowPage.substr(nowPage.find("<a href") + 9);
            int linkIndexStart = 0;
            int linkIndexEnd = nowPage.find("\">", linkIndexStart);
            links.push_back(nowPage.substr(linkIndexStart, linkIndexEnd - linkIndexStart));
        }
        
        Info info;
        info.index = i;
        info.links = links;
        info.baseScore = baseScore;
        m[url] = info;
    }
    
    for (auto i : m) {
        Info info = i.second;
        vector<string> links = info.links;
        
        for (int i = 0; i < links.size(); ++i)
            if (m.find(links[i]) != m.end() && info.baseScore != 0)
                m[links[i]].linkScore += (double) info.baseScore / links.size();
    }
    
    vector<pair<double, int>> result;
    
    for (auto i : m) {
        Info info = i.second;
        info.matcingScore = info.baseScore + info.linkScore;
        result.push_back({ info.matcingScore, info.index });
    }
    
    return (*min_element(result.begin(), result.end(), cmp)).second;
}
