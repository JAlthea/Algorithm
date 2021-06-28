using namespace std;

long long solution(int a, int b) {
    return a < b? (long long)(b - a + 1) * (a + b) / 2 : (long long)(a - b + 1) * (a + b) / 2;
}
