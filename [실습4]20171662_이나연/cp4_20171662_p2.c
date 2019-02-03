#include <stdio.h>

void mat_mul(int a[100][100], int b[100][100], int c[100][100],int N);

int main(void)
{
	int N;
	int a[100][100],b[100][100],c[100][100];
	int i,j;

	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&*(*(a+i)+j));
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			scanf("%d",&*(*(b+i)+j));
	}

	mat_mul(a,b,c,N);

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf("%d ",*(*(c+i)+j));

		printf("\n");
	}
	
}


void mat_mul(int a[100][100],int b[100][100],int c[100][100],int N)
{
	int i,j,k;
	int sum;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			sum=0;
			for(k=0;k<N;k++)
				sum += *(*(a+i)+k) * (*(*(b+k)+j));
			*(*(c+i)+j)=sum;
		}
	}
}
