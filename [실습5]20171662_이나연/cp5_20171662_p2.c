#include <stdio.h>

void swap(int*a, int*b);
void sort(int *a, int m);
void all_sort(int a[][100],int n, int m);
int binary_search(int *a, int *endPtr, int key, int **findPtr);
int all_binary_search(int a[][100], int n, int m, int key, int **findPtr);

int main(void)
{
	int a[100][100];
	int N,M,K;
	int *findPtr;
	
	int i,j;

	scanf("%d %d %d",&N, &M, &K);
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d",&a[i][j]);	
	}
	
	all_sort(a,N,M);

	printf("%d\n",all_binary_search(a,N,M,K,&findPtr));
	
	if(all_binary_search(a,N,M,K,&findPtr)==1)
		printf("%p\n",findPtr);

}

void swap(int*a, int*b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(int *a, int m)
{
	int i,j;

	for(i=1;i<m;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[i])
				swap(&a[i],&a[j]);
		}
	}
}

void all_sort(int a[][100],int n, int m)
{
	int i;

	for(i=0;i<n;i++)
		sort(a[i],m);
}

int binary_search(int *a, int *endPtr, int key, int **findPtr)
{
	int *firstPtr;
	int *midPtr;
	int *lastPtr;
	
	firstPtr = a;
	lastPtr = endPtr;

	while (firstPtr <= lastPtr)
	{
		midPtr = firstPtr + (lastPtr - firstPtr)/2;

		if(key > *midPtr)
			firstPtr = midPtr + 1;

		else if(key < *midPtr)
			lastPtr = midPtr - 1;

		else
			firstPtr = lastPtr + 1;
	}

	*findPtr = midPtr;

	return (key == *midPtr);
}

int all_binary_search(int a[][100], int n, int m, int key, int **findPtr)
{
	int i;
	

	for(i=0;i<n;i++)
	{
		if(binary_search(a[i],&a[i][m-1],key,findPtr)==1)
		return 1;	
	}

		return 0;
}


