using namespace std;

int solution(int n) {
    if (n < 3)
        return n;
    
    int a = 2, b = 1;
    for (int i = 3; i <= n; ++i) {
        int tmp = a;
        a += b;
        b = tmp;
        a > 1000000006 ? a %= 1000000007 : a;
    }
    
    return a;
}
