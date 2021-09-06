using namespace std;

int sequence(int n, int S) {
    if (2 * S % n)
        return 0;
    
    int a = (2 * S) / n + 1 - n;
    if (a < 1 || a % 2)
        return 0;
    
    return a >>= 1;
}

int solution(int n) {
    int count = 1;
    for (int i = 2; i <= n / 2; ++i)
        if (sequence(i, n))
            ++count;
    return count;
}
