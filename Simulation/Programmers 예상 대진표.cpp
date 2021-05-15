int solution(int n, int a, int b)
{
    int c = 0;
    while (a != b)
    {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        c++;
    }
    return c;
}
