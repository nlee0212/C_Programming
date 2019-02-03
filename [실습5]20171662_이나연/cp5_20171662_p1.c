#include <stdio.h>

void swap(int*a,int *b);
void sort(int *a, int m);
void print_array(int *a, int m);
void all_sort(int a[][100],int n,int m);
void print_all_array(int a[][100], int n, int m);

int main(void)
{
	int N,M;
	int i,j;
	int a[100][100];

	scanf("%d %d",&N,&M);

	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d",&a[i][j]);
	}

	all_sort(a,N,M);
	print_all_array(a,N,M);
}

void swap(int*a,int *b)
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

void print_array(int *a, int m)
{
	int i;

	for(i=0;i<m;i++)
		printf("%d ",a[i]);

	printf("\n");
}

void all_sort(int a[][100],int n,int m)
{
	int i;

	for(i=0;i<n;i++)
		sort(a[i],m);
}

void print_all_array(int a[][100], int n, int m)
{
	int i;

	for(i=0;i<n;i++)
		print_array(a[i],m);
}
