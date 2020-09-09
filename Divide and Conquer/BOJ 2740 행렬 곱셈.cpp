#import <ios>

int a[100][100], b[100][100], n, m, k, i, j, x, y;
int main()
{
  scanf("%d%d", &n, &m);
  for(i=0; i<n; ++i)
    for(j=0; j<m; ++j)
      scanf("%d", &a[i][j]);
	
  scanf("%d%d", &m, &k);
  for(i=0; i<m; ++i)
    for(j=0; j<k; ++j)
      scanf("%d", &b[i][j]);
      
  for(x=0; x<n; ++x, puts(""))
    for(y=0; y<k; ++y, printf("%d ", j))
      for(j=0, i=0; i<m; ++i)
        j += a[x][i] * b[i][y];
}
