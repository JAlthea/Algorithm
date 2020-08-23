#import <iostream>

int c2(int n)
{
    int c = 0;
    do
        c += n >> 1;
    while(n >>= 1);
    return c;
}

int c5(int n) 
{
    int c = 0;
    do 
        c += n / 5;
    while(n /= 5);
    return c;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::cout << std::min(c2(n) - c2(k) - c2(n - k), c5(n) - c5(k) - c5(n - k));
}
