using namespace std;

bool solution(int x) {
    int n = x, sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return x % sum ? false : true;
}
