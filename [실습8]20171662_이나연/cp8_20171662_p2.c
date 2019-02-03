#include <stdio.h>
#include <stdlib.h>

void push_back(int **a, int *size, int value);
void pop_back(int **a, int *size);
double average(int *a, int size);
double variance(int *a, int size);

int main(void)
{
	int *a;
	int N, size=0;
	int i,j;
	int num;
	int value;

	a = (int*) calloc (size , sizeof(int));

	scanf("%d", &N);

	for(i=0;i<N;i++)
	{
		scanf("%d", &num);

		if(num==1)
		{
			scanf("%d",&value);

			push_back(&a,&size,value);

			for(j=0;j<size;j++)
				printf("%d ",a[j]);

			printf("\n");
			printf("%lf %lf\n",average(a,size), variance(a,size));
		}

		else
		{
			pop_back(&a,&size);

			for(j=0;j<size;j++)
				printf("%d ",a[j]);

			printf("\n%lf %lf\n",average(a,size), variance(a,size));
		}
	}
}


double variance (int *a, int size)
{
	double av;
	double sum;
	int i;

	av = average(a,size);

	for (i=0;i<size;i++)
		sum += (a[i] - av) * (a[i] - av);

	return sum/(double)size;
}
double average (int *a, int size)
{
	int i;
	double sum=0;

	for(i=0;i<size;i++)
	{
		sum += a[i];
	}

	return sum/(double)size;
}
void push_back(int **a, int *size, int value)
{
	*size += 1;

	*a = realloc (*a, (*size)*sizeof(int));

	*(*a+*size-1) = value;
}
void pop_back(int **a, int *size)
{
	*size -= 1;

	*(*a+*size) = 0;

	*a = realloc (*a, (*size)*sizeof(int));
}
