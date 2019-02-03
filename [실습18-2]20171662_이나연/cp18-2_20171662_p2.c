#include <stdio.h>

typedef struct {
	float price;
	float number;
}Buying;

Buying getAverage(Buying* pBuying, int n);

int main(void)
{
	int N;
	int i;

	scanf("%d", &N);

	Buying *stuff;
	Buying av;

	stuff = (Buying*)malloc(sizeof(Buying)*(N));

	for (i = 0;i < N;i++)
		scanf("%f %f", &stuff[i].price, &stuff[i].number);

	av=getAverage(stuff, N);

	printf("%.2f %.2f\n", av.price, av.number);

	return 0;
}

Buying getAverage(Buying* pBuying, int n)
{
	float pav=0, nav=0;
	float ptemp=0, ntemp=0;
	int i;
	Buying average;

	for (i = 0;i < n;i++)
	{
		ptemp += pBuying[i].price;
		ntemp += pBuying[i].number;
	}

	average.price = ptemp / n;
	average.number = ntemp / n;

	return average;
}