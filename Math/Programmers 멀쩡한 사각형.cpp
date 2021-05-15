inline int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}
long long solution(int w, int h) {
    return (long long)w * h - w - h + gcd(w, h);
}
