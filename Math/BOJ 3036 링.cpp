#import <ios>
int n, k, t, q;
int gcd(int a,int b) { return a % b ? gcd(b, a % b) : b; }
int main()
{
    scanf("%d%d", &n, &k);
    for(int i=0; i<n-1; ++i)
    {
        scanf("%d", &t);
        q = gcd(k, t);
        printf("%d/%d ", k / q, t / q);
    }
}
