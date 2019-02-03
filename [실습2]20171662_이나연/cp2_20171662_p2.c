#include <stdio.h>

void sort4(int*, int*, int*, int*);

int main(void)
{
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	sort4(&a, &b, &c, &d);

	printf("%d %d %d %d\n", a, b, c, d);
}

void sort4(int*a, int*b, int*c, int*d)
{
	int temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}

	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}

	if (*a > *d)
	{
		temp = *a;
		*a = *d;
		*d = temp;
	}

	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}

	if (*b > *d)
	{
		temp = *b;
		*b = *d;
		*d = temp;
	}

	if (*c > *d)
	{
		temp = *c;
		*c = *d;
		*d = temp;
	}
}