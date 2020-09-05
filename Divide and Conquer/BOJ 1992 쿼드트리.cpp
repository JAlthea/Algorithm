#import <ios>
int n; char d[64][64];

void f(int x,int y,int m)
{
	int a = 0,b = 0;
	for(int i=x; i<x+m; ++i)
		for(int j=y; j<y+m; ++j)
			d[i][j] - 48 ? ++a : ++b;
	if(a * b)
	{
		printf("(");
		f(x,y,m/2),f(x,y+m/2,m/2),f(x+m/2,y,m/2),f(x+m/2,y+m/2,m/2);
		printf(")");
	}
	else if(a)
		printf("1");
	else
		printf("0");
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf(" %c", &d[i][j]);
	f(0, 0, n);
}
