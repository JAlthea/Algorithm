#import <bits/stdc++.h>

int d[15], size, count;

bool check(int i, int j)
{
    for (int y = i - 1; y > 0; --y)
        if (d[y] == j || abs(j - d[y]) == i - y) 
            return false;
    return true;
}

void nQueen()
{
    int i, j;
    for (i = 1, j = 1; i > 0;)
    {
        if (check(i, j))
        {
            d[i] = j;
            j = 1;
            if (++i <= size) 
                continue;
        }
        else if (++j <= size)
        {
            continue;
        }
        
        if (i > size)
        {
            count++;
            j = d[--i] + 1;
        }
        
        while (j > size)
        {
            j = d[--i] + 1;
        }
    }
}

int main()
{
    scanf("%d", &size);
    nQueen();
    printf("%d", count);
}
