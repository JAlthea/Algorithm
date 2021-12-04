#import <ios>

long long n, m, c;
bool d[1000001];

int main() {
	scanf("%lld%lld", &n, &m);
	for (long long i = 2; i * i <= m; ++i) {
		long long t = (n / (i * i)) * i * i;
		if (t < n) t += i * i;
		for (long long j = t; j <= m; j += i * i)
			d[j - n] = true;
	}
    
	for (int i = 0; i <= m - n; ++i)
		if (d[i]) c++;
    
	printf("%lld", m - n + 1 - c);
}
