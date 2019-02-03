#include <stdio.h>

void swap(int*,int*);
void sort(int*,int);
void print_array(int*,int);

int main(void)
{
	int n;
	int i;
	int a[1000];

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	sort(a,n);
	print_array(a,n);

}

void swap(int*a,int*b)
{
	int temp;

	temp=*(a+0);
	*a=*b;
	*b=temp;
}

void sort(int*a, int n)
{
	int i,j;

	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[j]>a[i])
				swap(&a[j],&a[i]);
		}
	}
}

void print_array(int*a,int n)
{
	int i;

	for(i=0;i<n;i++)
		printf("%d ",a[i]);

	printf("\n");
}
