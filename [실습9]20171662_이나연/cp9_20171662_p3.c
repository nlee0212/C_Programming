#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N,M;

	scanf("%d %d",&N, &M);

	int **box;
	int i,j;
	int num;

	box = (int**) malloc (sizeof(int*) * (N+2));

	for(i=0;i<N+2;i++)
		box[i] = (int*) malloc (sizeof(int) * (M+1));

	for(i=1;i<N+1;i++)
	{
		for(j=0;j<M;j++)
			scanf("%d",&box[i][j]);
	}

	i=0;

	while(1)
	{
		for(j=0;j<M;j++)
		{
			if(box[i+1][j]==0)
			{
				i++;
				if(i==N+1)
				{
					num=j+1;
					printf("%d\n",num);
					return 0;
				}
				j--;
			}
		}

		num = M+1;
		break;
	}

	printf("%d\n",num);

	return 0;
}


