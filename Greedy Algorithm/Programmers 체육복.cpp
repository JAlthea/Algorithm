#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    
    for (int i=0; i<lost.size(); i++)
        a[lost[i] - 1]++;
    
    for (int i=0; i<reserve.size(); i++)
        b[reserve[i] - 1]++;
    
    for (int i=0; i<n; i++)
        if (b[i] - a[i] == 0)
            a[i] = b[i] = 0;

    for (int i=0; i<n; i++)
    {
        if (a[i])
        {
            if (i > 0 && b[i-1])
                b[i-1] = a[i] = 0;
            else if (i < n-1 && b[i+1])
                b[i+1] = a[i] = 0;
        }
    }
    
    int count = n;
    for (int i=0; i<n; i++)
        if (a[i])
            count--;
    
    return count;
}
