#include <ios>

int main()
{
    int a, b;
    while(scanf("%d%d", &a, &b))
    {
        if(!a)
            break;
        if(b % a == 0 && b / a)
            puts("factor");
        else if(a % b == 0 && a / b)
            puts("multiple");
        else
            puts("neither");
    }
}
