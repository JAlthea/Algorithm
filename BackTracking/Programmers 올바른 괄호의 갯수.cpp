#include <vector>
using namespace std;

int getCountParenCase(int n, int left, int right) { 
    if (n == right)
        return 1;
    
    int countLeft = 0, countRight = 0;
    if (left < n)
        countLeft = getCountParenCase(n, left + 1, right);
    
    if (left != right)
        countRight = getCountParenCase(n, left, right + 1);
    
    return countLeft + countRight;
}

int solution(int n) {
    return getCountParenCase(n, 0, 0);
}