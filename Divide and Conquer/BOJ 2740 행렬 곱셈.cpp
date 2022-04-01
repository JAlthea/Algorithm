#import <ios>

int main() {
  int n, m, k, a[100][100], b[100][100];

  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }

  scanf("%d%d", &m, &k);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      scanf("%d", &b[i][j]);
    }
  }
      
  for (int x = 0; x < n; ++x, puts("")) {
    for (int y = 0; y < k; ++y, printf("%d ", j)) {
      for (int j = 0, i = 0; i < m; ++i) {
        j += a[x][i] * b[i][y];
      }
    }
  }
}
