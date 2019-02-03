#include <stdio.h>

int main(void)
{
	int H,W,N;
	int nh,nw;

	scanf("%d %d %d",&H,&W,&N);

	nw = N/H + 1;
	nh = N - (N/H)*H;

	if(nh==0)
	{
		nh=H;
		nw-=1;
	}

	printf("%d%02d\n",nh,nw);
}
