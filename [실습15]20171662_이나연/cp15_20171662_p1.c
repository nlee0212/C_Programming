#include <stdio.h>

typedef struct
{
	int numerator;
	int denominator;
} FRACTION;

void multFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes2);

int main(void)
{
	char temp;

	FRACTION Fr1, Fr2, Res2;

	printf("x/y : ");
	scanf("%d %c %d", &Fr1.numerator, &temp, &Fr1.denominator);

	printf("x/y : ");
	scanf("%d %c %d", &Fr2.numerator, &temp, &Fr2.denominator);

	printf("\n");

	multFr(&Fr1, &Fr2, &Res2);

	printf("%d/%d * %d/%d = %d/%d\n", Fr1.numerator, Fr1.denominator, Fr2.numerator, Fr2.denominator, Res2.numerator, Res2.denominator);

	return 0;
}

void multFr(FRACTION* pFr1, FRACTION* pFr2, FRACTION* pRes2)
{
	pRes2->numerator = (pFr1->numerator) * (pFr2->numerator);
	pRes2->denominator = (pFr1->denominator) * (pFr2->denominator);
}
