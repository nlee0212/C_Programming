#include <stdio.h>

void swap(int*, int*);

int main (void)
{
	int a, b;

	scanf("%d %d", &a, &b);

	swap(&a, &b);

	printf("a: %d\nb: %d\n", a, b);
}

void swap(int*a, int*b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}