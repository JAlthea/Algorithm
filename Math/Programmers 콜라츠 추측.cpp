using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    
    while (n != 1) {
        if (answer > 499) return -1;
        
        n = n % 2 ? n * 3 + 1 : n >> 1;
        answer++;
    }
    
    return answer;
}
