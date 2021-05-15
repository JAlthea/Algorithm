#import <ios>
int a, b, c;
int main()
{
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", b < c ? a / (c - b) + 1 : -1);
}
