#include <ios>
int main()
{
    int l, p, t;
    scanf("%d%d", &l, &p);
    while (~scanf("%d", &t)) printf("%d ", t - l * p); 
}
