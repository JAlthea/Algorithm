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

StackTop *stack;

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
	now=stack->top;
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

int main()
{
	init();

	int n, d;
	char s[6];
	scanf("%d", &n);
	while(n--)
	{
		scanf("%s", s);
		if(!strcmp(s,"push"))
            scanf("%d", &d), push(d);
		if(!strcmp(s, "top"))
			printf("%d\n", top());
		if(!strcmp(s, "pop"))
			printf("%d\n", pop());
		if(!strcmp(s, "empty"))
			printf("%d\n", empty());
		if(!strcmp(s, "size"))
			printf("%d\n", size());
	}
}
