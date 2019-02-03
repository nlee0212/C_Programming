#include <stdio.h>

void*f(void*,void*,int);

int main(void)

{
	int option;
	int a,b;
	float fa,fb;
	double da,db;
	void *pa,*pb,*ans;

	scanf("%d",&option);

	if(option==0)
	{
		scanf("%d %d",&a,&b);
		pa=&a;
		pb=&b;
	}
	

	if(option==1)
	{
		scanf("%f %f",&fa,&fb);
		pa=&fa;
		pb=&fb;
	}

	if(option==2)
	{
		scanf("%lf %lf",&da,&db); 
		pa=&da;
		pb=&db;
	}

	ans=f(pa,pb,option);

	if(option==0)
		printf("%d\n",*(int*)ans);

	if(option==1)
		printf("%f\n",*(float*)ans);

	if(option==2)
		printf("%lf\n",*(double*)ans);
	
}

void*f(void*pa,void*pb,int option)
{
	switch(option){
	case 0:
	if(*(int*)pa<*(int*)pb)
		return pa;
	else
		return pb;
	break;
	case 1:
	if(*(float*)pa<*(float*)pb)
		return pa;
	else
		return pb;
	break;
	case 2:
	if(*(double*)pa<*(double*)pb)
		return pa;
	else
		return pb;
	break;
	}
}
