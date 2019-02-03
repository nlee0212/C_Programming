#include <stdio.h>

union utemp{
	int i;
	float f;
	double d;
};

typedef struct {
	int type;
	char name[20];
	union utemp u;
}stemp;

void power(stemp *s);

int main(void)
{
	stemp temp[100];

	int it;
	int i;

	printf("Number of Iterations : ");
	scanf("%d", &it);

	for (i = 0;i < it;i++)
	{
		printf("Type [1 for int, 2 for float, 3 for double] : ");
		scanf("%d", &temp[i].type);

		switch (temp[i].type)
		{
		case 1: strcpy(temp[i].name, "integer");break;
		case 2: strcpy(temp[i].name, "float"); break;
		case 3: strcpy(temp[i].name, "double"); break;
		}

		switch (temp[i].type)
		{
		case 1: printf("Enter an integer value : "); scanf("%d", &temp[i].u.i); break;
		case 2: printf("Enter a float value : "); scanf("%f", &temp[i].u.f); break;
		case 3: printf("Enter a double value : "); scanf("%lf", &temp[i].u.d); break;
		}
	}

	printf("----------Result----------\n");

	for (i = 0;i < it;i++)
	{
		power(&temp[i]);
		
		switch (temp[i].type)
		{
		case 1: printf("%s\t: %d\n", temp[i].name, temp[i].u.i); break;
		case 2: printf("%s\t: %.4f\n", temp[i].name, temp[i].u.f); break;
		case 3: printf("%s\t: %.4lf\n", temp[i].name, temp[i].u.d); break;
		}
	}


	return 0;
}

void power(stemp *s)
{
	switch (s->type)
	{
	case 1: s->u.i = s->u.i*s->u.i; break;
	case 2: s->u.f = s->u.f*s->u.f; break;
	case 3: s->u.d = s->u.d*s->u.d; break;
	}
}