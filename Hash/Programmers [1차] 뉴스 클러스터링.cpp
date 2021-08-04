#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

int solution(string str1, string str2) {
    map<string, int> mapA;
    map<string, int> mapB;
    int size1 = str1.size();
    int size2 = str2.size();
    for (int i = 1; i < max(size1, size2); i++) {
        if (i < size1 && isalpha(str1[i - 1]) && isalpha(str1[i])) {
            string tmp = to_string(toupper(str1[i - 1])) + to_string(toupper(str1[i]));
            if (mapA.find(tmp) == mapA.end())
                mapA.insert({tmp, 1});
            else
                mapA[tmp]++;
        }
        if (i < size2 && isalpha(str2[i - 1]) && isalpha(str2[i])) {
            string tmp = to_string(toupper(str2[i - 1])) + to_string(toupper(str2[i]));
            if (mapB.find(tmp) == mapB.end())
                mapB.insert({tmp, 1});
            else
                mapB[tmp]++;
        }
    }

    int countInter = 0;
    int countUnion = 0;
    for (auto i = mapA.begin(); i != mapA.end(); ++i) {
        pair<string, int> p = *i;
        if (mapB.find(p.first) != mapB.end()) {
            countInter += min(mapA[p.first], mapB[p.first]);
            mapB[p.first] -= mapA[p.first];
        }
        countUnion += mapA[p.first];
    }
    for (auto i=mapB.begin(); i != mapB.end(); ++i) {
        pair<string, int> p = *i;
        if (mapB[p.first] > 0)
            countUnion += mapB[p.first];
    }

    if (countUnion == 0)
        return 65536;
    return (double) countInter / countUnion * 65536;
}
