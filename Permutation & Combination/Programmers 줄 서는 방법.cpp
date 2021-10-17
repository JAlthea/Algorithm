#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    for(int i = 1; i <= n; ++i) 
        answer.push_back(i);

    long long i = 1;
    do {
        if (k == i++)
            break;
    } while (next_permutation(answer.begin(), answer.end()));

    return answer;
}
