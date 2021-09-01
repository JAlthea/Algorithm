#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct File {
    string name;
    string head;
    int number;
    int index;
};

bool cmp(File & a, File & b) {
    string A = a.head;
    string B = b.head;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    transform(B.begin(), B.end(), B.begin(), ::tolower);
    if (A == B && a.number == b.number)
        return a.index < b.index;
    else if (A == B)
        return a.number < b.number;
    return A < B;
}

vector<string> solution(vector<string> files) {
    int size = files.size();
    vector<File> v(size);
    for (int i = 0; i < size; ++i) {
        string s = files[i];
        
        int k = 0;
        string head = "";
        while (!isdigit(s[k]))
            head += s[k++];
        string number = "";
        while (isdigit(s[k]))
            number += s[k++];
        
        v[i] = { files[i], head, stoi(number), i };
    }
   
    sort(v.begin(), v.end(), cmp);
    vector<string> answer(size);
    for (int i = 0; i < size; ++i)
        answer[i] = v[i].name;
    
    return answer;
}
