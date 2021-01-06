#import <ios>
#define ll long long

int a, b, c;

int m(ll x) { return x < c ? x : x % c; }

int f(int x, int n)
{
	if (n == 1) return m(x);
  
	if (n % 2)
	{
		ll t = f(x, n - 1);
		t = m(t);
		return m(x * t);
	}
	else
	{
		ll t = f(x, n / 2);
		t = m(t);
		return m(t * t);
	}
}

int main()
{
	scanf("%d%d%d", &a, &b, &c);
	printf("%d", f(a, b));
}
