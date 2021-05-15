#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    string tmp = phone_book[0];
    for (int i=1; i<phone_book.size(); i++)
    {
        if (phone_book[i].substr(0, tmp.size()) == tmp) 
            return false;
        tmp = phone_book[i];
    }
    return true;
}
