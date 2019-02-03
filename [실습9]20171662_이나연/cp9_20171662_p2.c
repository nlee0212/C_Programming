#include <stdio.h>
#include <stdlib.h>

void upper_to_lower(char str[]);
void lower_to_upper(char str[]);

int main(void)
{
	char str1[]="There's no Free Lunch";
	char str2[]="123AbCdEfGh";
	int i=0,j=0;
	int k;
	
	upper_to_lower(str1);
	printf("%s\n",str1);
	lower_to_upper(str1);
	printf("%s\n",str1);
	upper_to_lower(str2);	
	printf("%s\n",str2);
	lower_to_upper(str2);
	printf("%s\n",str2);
}


void upper_to_lower(char str[])
{
	int i=0;

	while(str[i] != '\0')
	{
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
}

void lower_to_upper(char str[])
{
	int i=0;

	while(str[i] != '\0')
	{
		if(str[i] >= 97 && str[i] <= 122)
			str[i] -= 32;
		i++;
	}

}
