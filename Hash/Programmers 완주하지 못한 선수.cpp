#include <string>
#include <algorithm>
using namespace std;

//Answer1
string solution(vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i=0; i<participant.size(); i++)
        if (participant[i] != completion[i])
            return participant[i];
}

//Answer2
//participant의 원소들을 completion을 넣은 set을 검사하면서 존재하지 않으면 그 원소를 리턴시키는 방법
