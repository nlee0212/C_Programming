#include <stdio.h>

int main(void)
{
	double a, b, c, d;
	double *pa, *pb, *pc, *pd;

	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

	pa = &a;
	pb = &b;
	pc = &c;
	pd = &d;

	if (*pa == *pc)
	{
		if (*pb == *pd)
			printf("oo\n");

		else
			printf("0\n");
	}

	else
		printf("1\n");
}