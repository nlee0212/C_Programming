#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strncpy(char *a, char *b, int n);
void initialization(char *a, int n);

int main(void)
{
	char *str1, str[20];
	int i;

	printf("input str : ");
	fgets(str,sizeof(str),stdin);

	str[strlen(str)-1]='\0';

	str1 = (char*) malloc (sizeof(char)*strlen(str));

	strcpy(str1,str);

	for(i=0;i<strlen(str1)+1;i++)
	{
		initialization(str,strlen(str));
		my_strncpy(str, str1, i);
		printf("%s\n",str);
	}
	
	free(str1);

	return 0;
}

char *my_strncpy(char *a, char *b, int n)
{
	int i;

	for(i=0;i<n;i++)
		a[i]=b[i];

	return 0;
}

void initialization(char *a, int n)
{
	int i;

	for(i=0;i<n;i++)
		a[i]='*';
}
