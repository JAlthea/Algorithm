#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string convertToBinaryORBinary(int n, int m, int size) {
    string s = "";
    int twoNumberAnd = n | m;
    while (size--) {
        s = (twoNumberAnd % 2 ? '#' : ' ') + s;
        twoNumberAnd >>= 1;
    }
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for (int i = 0; i < n; ++i)
        answer[i] = convertToBinaryORBinary(arr1[i], arr2[i], n);
    return answer;
}
