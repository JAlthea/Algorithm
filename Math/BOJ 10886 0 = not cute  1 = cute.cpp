#import <ios>
int n, s, a;
int main() {
    scanf("%d", &n);
    while (~scanf("%d", &a)) s += a;
    printf("Junhee is %scute!", n > 2 * s ? "not " : "");
}
