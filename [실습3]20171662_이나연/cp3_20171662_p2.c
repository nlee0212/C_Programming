#include <stdio.h>

int is_prime(int ***a);

int main(void)
{
	int a;
	int *pa;
	int **ppa;

	scanf("%d",&a);

	pa=&a;
	ppa=&pa;

	printf("%d\n",is_prime(&ppa));
}

int is_prime(int ***a)
{
	int j,rem;
	
	if(***a<=1)
		return 0;

	else
	{
	if(***a==2)
		return 1;

	if(***a!=2&&***a%2==0)
		return 0;

	if(***a%2!=0)
	{
		

		for(j=1;2*j+1<=***a;j++)
		{
			rem=0;
			if ((***a)%(2*j+1)==0)
				rem++;
		}

		if(rem==1)
			return 1;
		else
			return 0;
		}

	}

	

}
