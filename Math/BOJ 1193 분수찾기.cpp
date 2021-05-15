#import <ios>
int n, i, s, c;
int main()
{
    scanf("%d", &n);
    while (s < n) 
        s + = i++;
    i--;
	c = 1;
    while (s != n)
        s--, c++;
    i % 2 == 0 ? printf("%d/%d", i - c + 1, c) : printf("%d/%d", c, i - c + 1);
}
