#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i<skill_trees.size(); i++)
    {
        int k = 0;
        for (int j = 0; j<skill_trees[i].size(); j++)
        {
            if (skill[k] == skill_trees[i][j])
                k++;
        }

        if (k == skill.size())
            answer++;
        else
        {
            int count = 0;
            for (int j = k; j<skill.size(); j++)
            {
                if (skill_trees[i].find(skill[j]) != string::npos)
                {
                    count++;
                    break;
                }
            }
            if (!count)
                answer++;
        }
    }
    
    return answer;
}
