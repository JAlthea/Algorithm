#import <iostream>
int a, b, v;
int main()
{
    std::cin >> a >> b >> v;
    std::cout << (v - b - 1) / (a - b) + 1;
}
