#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    
    int d = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            ++d;
            if (d == k)
            {
                cout << i;
                return 0;
            }
        }
    }
  
    cout << 0;
}
