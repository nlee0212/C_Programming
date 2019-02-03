#include <stdio.h>
#include <stdlib.h>

int *get_next_process(int *prev_pointer, int size);
int swap(int *a, int *b);
void sort(int *a, int m); 
void backsort(int *a, int m);

int main(void)
{
	int N;
	int i;
	
	scanf("%d",&N);

	int *a = (int *) malloc (sizeof(int)*N);
	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);

	sort(a,N);

	while(N > 1)
	{
		a = get_next_process(a,N);


		if(N%2==0)
			N = N/2;
		else
			N = N/2 + 1;

		for(i=0;i<N;i++)
			printf("%d ",a[i]);

		printf("\n");

	}
}





int *get_next_process(int *prev_pointer, int size)
{
	int next_size;
	int *next_pointer;
	int i;

	if(size%2==0)
		next_size = size/2;

	else
		next_size = size/2 + 1;

	next_pointer = (int *) malloc (sizeof(int) * next_size);

	backsort(prev_pointer,size);

	if(size%2 == 0)
	{
		for(i=0;i<size/2;i++)
			next_pointer[i] = prev_pointer[2*i] + prev_pointer[2*i + 1];
	}

	else
	{
		for(i=0;i<size/2;i++)
			next_pointer[i] = prev_pointer[2*i] + prev_pointer[2*i + 1];

		next_pointer[size/2] = prev_pointer[size - 1];
	}

	return next_pointer;
}

int swap(int *a, int *b)
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

void backsort(int *a, int m)
{
	int i,j;

	for(j=1;j<m;j++)
	{
		for(i=0;i<j;i++)
		{
			if(a[i]<a[j])
				swap(&a[i],&a[j]);
		}
	}
}
