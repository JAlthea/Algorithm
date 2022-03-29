#import <ios>

int n, d[2200][2200], s[3];

void f(int x, int y, int k) {
    int a = b = c = 0;
    
    for (int i = x; i < x + k; ++i) {
        for (int j = y; j< y + k; ++j) {
            if (d[i][j] == -1) {
                ++a;
            }
            else if(d[i][j] == 0) {
                ++b;
            }
            else if(d[i][j] == 1) {
                ++c;
            }
        }
    }
    
    if (!a && !b) {
        ++s[2];
    }
    else if (!b && !c) {
        ++s[0];
    }
    else if (!c && !a) {
        ++s[1];
    }
    else {      
        for (int i = x; i < x + k; i += k / 3)
            for (int j = y; j < y + k; j += k / 3)
                f(i, j, k / 3);
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
    
    printf("%d %d %d", s[0], s[1], s[2]);
}
