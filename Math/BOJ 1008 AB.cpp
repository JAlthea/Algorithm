#include <ios>

inline double div(short a, short b)
{
	return (double) a / b;
}

int main()
{
	short a, b;
	scanf("%hd %hd", &a, &b);
	printf("%.10lf\n", div(a, b));
}
