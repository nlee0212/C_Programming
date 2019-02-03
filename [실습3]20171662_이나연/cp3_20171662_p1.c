#include <stdio.h>

void f(int *, int *, int *, int );

int main(void)
{
	int H,M,S,T;

	scanf("%d %d %d %d", &H, &M, &S, &T);

	f(&H, &M, &S, T);

	printf("%02d:%02d:%02d\n",H,M,S);
}


void f(int *H, int *M, int *S, int T)
{
	int sec;

	sec=*H*3600+*M*60+*S+T;

	*H=sec/3600;
	*M=(sec%3600)/60;
	*S=sec%60; 
}
