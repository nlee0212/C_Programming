#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	int **pascal;
	int i,j;

	scanf("%d",&N);
	pascal = (int**) malloc (sizeof(int*) * N);

	for(i=0;i<N;i++)
		pascal[i] = (int*) malloc (sizeof(int) * N);



	for(i=0;i<N;i++)
	{
		pascal[i][0] = 1;
		pascal[i][i] = 1;
	}

	for(i=2;i<N;i++)
	{
		for(j=1;j<i;j++)
			pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<i+1;j++)
			printf("%d",pascal[i][j]);
		printf("\n");
	}

	return 0;
}
