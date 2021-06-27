#import <ios>
int main() {
    int k, d, a;
    scanf("%d/%d/%d", &k, &d, &a);
    puts(k + a < d || !d ? "hasu" : "gosu");
}
