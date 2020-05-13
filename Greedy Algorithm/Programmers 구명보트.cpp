#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int size = people.size();
    for (int i=0, k=size - 1; i<=k; i++)
    {
        if (people[i] + people[k] <= limit)
            k--;
        answer++;
    }
    
    return answer;
}
