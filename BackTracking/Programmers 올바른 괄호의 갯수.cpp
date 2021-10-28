#include <vector>
using namespace std;

int AllParenCase(int n, int left, int right) { 
    if (n == right)
        return 1;
    
    int countLeft = 0, countRight = 0;
    if (left < n)
        countLeft = AllParenCase(n, left + 1, right);
    
    if (left != right)
        countRight = AllParenCase(n, left, right + 1);
    
    return countLeft + countRight;
}

int solution(int n) {
    return AllParenCase(n, 0, 0);
}
