#import <ios>

int main()
{
    int h, m, c;
    scanf("%d%d%d", &h, &m, &c);
    m += c; h += m / 60; m %= 60; h %= 24;
    printf("%d %d", h, m);
}
