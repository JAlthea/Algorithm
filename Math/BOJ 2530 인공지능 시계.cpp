#import <ios>
int main()
{
    int h, m, s, d;
    scanf("%d%d%d%d", &h, &m, &s, &d);
    s += d;
    int ts = s - (s / 60 * 60);
    m += s / 60;
    int tm = m % 60;
    h += m / 60;
    int th = h % 24;
    printf("%d %d %d", th, tm, ts);
}
