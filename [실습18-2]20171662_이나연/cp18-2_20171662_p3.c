#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int strCmpPk(char* s1, char* s2);
void strPk(char* s1, char*s2);

int main(void)
{
	char* s1, *s2;
	int ret;

	s1=(char*)malloc(sizeof(char)*100);
	s2=(char*)malloc(sizeof(char)*100);

	printf("first string : ");
	fgets(s1, 100, stdin);

	printf("second string : ");
	fgets(s2, 100, stdin);

	strPk(s1, s2);

	ret=strCmpPk(s1, s2);

	if(ret==0)
		printf("string1 == string2\n");

	if(ret>0)
		printf("string1 > string2\n");

	if(ret<0)
		printf("string1 < string2\n");

	return 0;
}

int strCmpPk(char* s1, char* s2)
{
	return strcmp(s1, s2);
}

void strPk(char* s1, char*s2)
{
	char* temp1, *temp2;
	int i,j=0;

	temp1 = (char*)malloc(sizeof(char)*100);
	temp2 = (char*)malloc(sizeof(char)*100);

	for(i=0; i<strlen(s1); i++)
	{
		if(s1[i]<='z'&&s1[i]>='a')
			temp1[j++]=s1[i];

		if(s1[i]<='Z'&&s1[i]>='A')
			temp1[j++]=s1[i];
	}

	temp1[j]='\0';

	j=0;

	for(i=0; i<strlen(s2); i++)
	{
		if(s2[i]<='z'&&s2[i]>='a')
			temp2[j++]=s2[i];

		if(s2[i]<='Z'&&s2[i]>='A')
			temp2[j++]=s2[i];
	}

	temp2[j]='\0';

	strcpy(s1, temp1);
	strcpy(s2, temp2);
}


