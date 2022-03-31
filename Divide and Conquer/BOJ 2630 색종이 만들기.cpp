#import <ios>

int n, d[128][128], s[2];

void f(int x, int y, int m) {
    int a = b = 0;
    
    for (int i = x; i < x + m; ++i) {
        for (int j = y; j < y + m; ++j) {
            d[i][j] ? ++a : ++b;
        }
    }
    
    if (a & b) {
        f(x, y, m / 2), f(x + m / 2, y, m / 2), f(x, y + m / 2, m / 2), f(x + m / 2, y + m / 2, m / 2);
    }
    else if (a) {
        ++s[1];
    }
    else {
        ++s[0];
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &d[i][j]);
        }
    }
    
    f(0, 0, n);
    
    printf("%d\n%d", s[0], s[1]);
}
