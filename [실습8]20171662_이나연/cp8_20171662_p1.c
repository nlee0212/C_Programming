#include <stdio.h>
#include <stdlib.h>

void double_double(int**a, int*size);
void sort(int *a, int m);
void swap(int *a, int *b);

int main(void)
{
	int N;
	int *a;
	int i,j;

	scanf("%d",&N);

	a = (int *) malloc (sizeof(int)*N);

	for(i=0;i<N;i++)
		scanf("%d",&a[i]);

	for(i=0;i<3;i++)
		{
			double_double(&a,&N);

			N = N*2;

			for(j=0;j<N;j++)
				printf("%d ",a[j]);

			printf("\n");
		}
	free(a);
	return 0;
}

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *a, int m)
{
	int i,j;

	for(j=1;j<m;j++)
	{
		for(i=0;i<j;i++)
		{
			if(a[i]>a[j])
				swap(&a[i],&a[j]);
		}
	}
}

void double_double(int**a, int*size)
{
	*a = realloc (*a,((*size)*2)*sizeof(int));

	int i;

	for(i=0;i<(*size);i++)
		*(*a+i+*size) = 2 * (*(*a+i));
	
	sort(*a,(*size)*2);


}
