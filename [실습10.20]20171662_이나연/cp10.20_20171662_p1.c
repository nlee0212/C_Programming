#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_string(char *str, char *string_1, char *string_2);

int main(void)
{
	char str[52], *string_1, *string_2;
	int i;

	
	string_1 = (char*) malloc (sizeof(char)*25);
	string_2 = (char*) malloc (sizeof(char)*25);
	
	printf("input str : ");

	fgets(str, sizeof(str), stdin);

	printf("%s",str);

	split_string(str,string_1,string_2);

	str[strlen(str)-1]='\0';

	printf("[%s] -> [%s] [%s]\n",str, string_1, string_2);


	free(string_1);
	free(string_2);

	return 0;
}

void split_string(char *str, char *string_1, char *string_2)
{
	int length;
	int i;

	length = strlen(str)-1;

	string_1 = strncpy(string_1,str,length/2);

	string_2 = strncpy(string_2,str+(length/2),length/2);
}


