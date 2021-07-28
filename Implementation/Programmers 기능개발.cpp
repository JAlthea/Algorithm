#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int k = 0;
    while (k < speeds.size()) {
        for (int i = 0; i < speeds.size(); ++i)
            progresses[i] += speeds[i];

        int count = 0;
        while (k < speeds.size()) {
            if (progresses[k] < 100)
                break;

            count++;
            k++;
        }

        if (count) answer.push_back(count);
    }

    return answer;
}
