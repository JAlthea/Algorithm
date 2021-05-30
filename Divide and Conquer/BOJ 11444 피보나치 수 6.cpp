#include <bits/stdc++.h>
using namespace std;

const long long m = 1e9 + 7;
inline long long mod(long long k) { return k >= m ? k %= m : k; }

long long fastFibo(long long n)
{
	long long a = 1, b = 0, p = 0, q = 1, tmpA, tmpB, tmpP, tmpQ;

	while (n > 0)
	{
		if (n % 2 == 0)
		{
			tmpP = mod((p*p) + (q*q));
			tmpQ = mod((q*q) + (2 * p*q));
			p = tmpP;
			q = tmpQ;
			n /= 2;
		}
		else
		{
			tmpA = mod((b*q) + (a*q) + (a*p));
			tmpB = mod((b*p) + (a*q));
			a = tmpA;
			b = tmpB;
			--n;
		}
	}
    
	return b;
}

int main() {
	long long n;
	cin >> n;
	cout << fastFibo(n);
}
