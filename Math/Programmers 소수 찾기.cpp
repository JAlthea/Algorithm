#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int d[1000001];
    for (int i = 2; i < 1000001; ++i)
        d[i] = 1;
    
    for (int i = 2; i * i < 1000001; ++i)
        if (d[i])
            for (int j = i + i; j < 1000001; j += i)
                d[j] = 0;
    
    int result = 0;
    for (int i = 2; i <= n; ++i)
        if (d[i])
            result++;
  
    return result;
}
