#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = (int)1e9;
    sort(dist.begin(), dist.end());
    do
    {
        vector<int> line = weak;
        for (int i = 0; i < line.size(); i++)
        {
            int result = (int)1e9;
            int index = 0;
            for (int j = 0; j < dist.size(); j++)
            {
                int nowDist = dist[j];
                int startLine = line[index];
                int nextLine = line[index];
                while (nowDist >= nextLine - startLine)
                {
                    nowDist -= nextLine - startLine;
                    index++;
                    if (index == line.size())
                        break;
                    startLine = nextLine;
                    nextLine = line[index];
                }

                if (index == line.size())
                {
                    result = j + 1;
                    break;
                }
            }

            line.push_back(line[0] + n);
            line.erase(line.begin());

            if (answer > result)
                answer = result;
        }

    } while (next_permutation(dist.begin(), dist.end()));

    if (answer >= 9)
        return -1;
    return answer;
}
