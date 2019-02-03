#include <stdio.h>

int main(void)
{
	int a,b,c;
	int *pa, *pb, *pc;

	scanf("%d %d %d", &a, &b, &c);

	pa = &a;
	pb = &b;
	pc = &c;

	if (*pa>*pb)
	{
		if (*pb>*pc)
		{
			printf("%d %d\n", *pc, *pa);
			printf("%p %p\n", pc, pa);
		}

		else
		{
			if(*pa>*pc)
			{
				printf("%d %d\n", *pb, *pa);
				printf("%p %p\n", pc, pa);
			}	

			else
			{
				printf("%d %d\n", *pb, *pc);
				printf("%p %p\n", pc, pa);
			}
		}

	}

	else
	{
		if (*pa>*pc)
		{
			printf("%d %d\n", *pc, *pb);
			printf("%p %p\n", pc, pa);
		}

		else
		{
			if (*pb>*pc)
			{
				printf("%d %d\n", *pa, *pb);
				printf("%p %p\n", pc, pa);
			}

			else
			{
				printf("%d %d\n", *pa, *pc);
				printf("%p %p\n", pc, pa);
			}
		}
	}
	
	
}
