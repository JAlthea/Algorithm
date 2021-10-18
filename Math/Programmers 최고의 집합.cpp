#include <vector>
using namespace std;

vector<int> solution(int n, int s) {
    int a = s / n;
    if (!a)
        return { -1 };
    
    vector<int> answer(n);
    int sub = s - (n * a);
    
    for (int i = 0; i < n; ++i) {
        answer[i] = a;
        if (n - sub <= i)
            ++answer[i];
    }

    return answer;
}
