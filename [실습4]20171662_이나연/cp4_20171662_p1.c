#include <stdio.h>

void shift_right(int*);
void shift_n_right(int*,int);
void print_array(int*);

int main(void)
{
	int n;
	int a[10]={1,2,3,4,5,6,7,8,9,10};

	scanf("%d",&n);

	shift_n_right(a,n);

	print_array(a);

	printf("\n");
}

void shift_right(int*a)
{
	int b[10];
	int i;

	for(i=0;i<9;i++)
		*(b+i+1)=*(a+i);

	*(b+0)=*(a+9);

	for(i=0;i<10;i++)
		*(a+i)=*(b+i);
}	

void shift_n_right(int*a,int n)
{
	int i;

	for(i=0;i<n;i++)
		shift_right(a);
}

void print_array(int*a)
{
	int i;

	for(i=0;i<10;i++)
		printf("%d ",*(a+i));
}
