#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i;
	int num=0;
	char sent[100];
	
	fgets(sent, sizeof(sent), stdin); 

	while(1)
	{
		for(i=0;;i++)
		{
			if(sent[i]==' ')
			{
				if(sent[i+1]>=65 && sent[i+1]<=90)
					num++;

				if(sent[i+1]>=97 && sent[i+1]<=122)
					num++;
			}

			if(sent[i]=='\n')
				break;
		}

		if(sent[0]>=65 && sent[0]<=90)
			num ++;
			
		if(sent[0]>=97 && sent[0]<=122)
			num++;

		printf("%d\n",num);

		return 0;
	}

	return 0;
}


