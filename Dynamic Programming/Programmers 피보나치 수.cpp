using namespace std;

int solution(int n) {
    int d[100001] = { 0, 1 };
    
    for (int i = 2; i <= n; ++i) {
        d[i] = d[i - 1] + d[i - 2];
        if (d[i] > 1234566)
            d[i] %= 1234567;
    }
    
    return d[n];
}
