#import <ios>
int n, m, t, count, min = 99;
char d[51][51];
int main()
{
    scanf("%d%d",&n, &m);
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            scanf(" %c", &d[i][j]);

    for (int i=0; i<n-7; i++)
    {
        for (int j=0; j<m-7; j++)
        {
            count = 0;      
            for (int x=i; x<8+i; x++)
            {
                for (int y=j; y<8+j; y++)
                {
                    if((x + y) % 2 && d[x][y] == 'W')
                        count++;
                    else if((x + y) % 2 == 0 && d[x][y] == 'B')
                        count++;
                }
            }
            
            if (count > 32)
                count = 64 - count;
            if (min > count)
                min = count;
        }
    }
    
    printf("%d", min);
}
