#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer(commands.size());
    for (int i=0, k=0; i<commands.size(); i++)
    {
        vector<int> subArray(commands[i][1] - commands[i][0] + 1);
        copy(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1], subArray.begin());
        sort(subArray.begin(), subArray.end());
        answer[k++] = subArray[commands[i][2] - 1];
    }
    return answer;
}
