#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef struct StackList
{
	int value;
	struct StackList *link;
} StackList;

typedef struct StackTop
{
	int size;
	StackList *top;
} StackTop;

void init()
{
	stack = (StackTop*)malloc(sizeof(StackTop));
	stack->top = NULL;
	stack->size = 0;
}

int empty()
{
	return stack->top == NULL;
}

void push(int n)
{
	StackList *now = (StackList*)malloc(sizeof(StackList));
	now->value = n;
	now->link = stack->top;
	stack->top = now;
	stack->size++;
}

int pop()
{
	if(empty())
		return -1;
	StackList *now;
	now = stack->top;
	stack->top = now->link;
	int value = now->value;
	free(now);
	stack->size--;
	return value;
}

int size()
{
	return stack->size;
}

int top()
{
	if(!stack->size)
		return -1;
	return stack->top->value;
}

char d[200002];
int n, t, a[100001], c, r[100001], m;
StackTop *stack;

int main()
{
	init();

	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t);
		a[i] = t;
	}

	a[0] = 0;
	m = 1;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] - a[i - 1] >= 2)
		{
			int max = 0;
			int start = a[i - 1] + 1;
			int end = a[i];
			for(int j=start; j<=end; ++j)
			{
				if(!r[j])
				{
					max++;
					push(m);
					r[j]++;
					d[c++] = '+';
					m++;
				}
			}

			pop();
			d[c++] = '-';
		}
		else if(a[i] - a[i - 1] == 1)
		{
			push(m);
			r[a[i]]++;
			d[c++] = '+';
			pop();
			d[c++] = '-';
			m++;
		}
		else if(a[i - 1] - a[i] >= 2)
		{
			if (top() != a[i])
			{
				printf("NO");
				return 0;
			}

			pop();
			d[c++] = '-';
		}
		else if(a[i - 1] - a[i] == 1)
		{
			pop();
			d[c++] = '-';
		}
	}

	for(int i=0; i<c; ++i)
		printf("%c\n", d[i]);
}
