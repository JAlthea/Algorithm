#import <iostream>
int a, b;
int main() {
  std::cin >> b;
  while (std::cin >> a) b -= a;
  std::cout << b;
}
