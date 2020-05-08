long long solution(int N) {
    long long a = 1, b = 0, t;
    for (int i=2; i<=N+1; i++)
    {
        t = a;
        a += b;
        b = t;
    }
    return a * 2 + b * 2;
}
