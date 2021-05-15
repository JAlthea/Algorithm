#import <ios>

int sum, now, t, index;

int main()
{
    for (int i=0; i<5; ++i)
    {
        now = 0;
        for (int j=0; j<4; ++j)
        {
            scanf("%d", &t);
            now += t;
        }

        if (sum < now) 
        {
            sum = now;
            index = i + 1;
        }
    }
    
    printf("%d %d", index, sum);
}
