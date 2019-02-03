#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[17];
	int i,j;
	int digit=0, numdigit=0;
	long int num=0;
	long int temp;

	fgets(str,sizeof(str),stdin);

	for(i=0;i<16;i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			digit++;
			numdigit++;
		}

		else if(str[i]=='K')
		{
			digit += 3;
			break;
		}

		else if(str[i]=='M')

		{
			digit += 6;
			break;
		}
		
			
		else if(str[i]=='G')
		{
			digit += 9;
			break;
		}
			
		else if(str[i]=='T')
		{
			digit += 12;
			break;
		}

		else if(str[i]=='P')
		{
			digit += 15;
			break;
		}

		else
			break;
	}

	if(digit==0)
	{
		printf("%s",str);
		
		return 0;
	}

	else
	{
		for(i=0;i<numdigit;i++)
		{
			temp = str[i] - 48;

			for(j=0;j<digit-i-1;j++)
			{
				temp *= 10;
			}

			num += temp;
		}
	}

	if(digit>=1 && digit<=3)
		printf("%ld\n",num);

	if(digit>=4 && digit<=6)
		printf("%ldK\n",num/1000);

	if(digit>=7 && digit<=9)
		printf("%ldM\n",num/1000000);

	if(digit>=10 && digit<=12)
		printf("%ldG\n",num/1000000000);

	if(digit>=13 && digit<=15)
		printf("%ldT\n",num/1000000000000);

	if(digit>=16 && digit<=18)
		printf("%ldP\n",num/1000000000000000);

	return 0;
}
