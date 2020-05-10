#include <vector>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for (int n=3; n<2500; n++)
    {
        for (int m=3; n+m<=2502; m++)
        {
            if (m > n)
                break;
            
            if (n + m == (brown + 4) >> 1 && n * m == brown + red)
                return {n, m};
        }
    }
    return answer;
}
