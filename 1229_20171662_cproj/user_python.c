#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char* name;
	char* content;
} string;

char* plusreturn(char* input, string* string, int plus);
char* multreturn(char* input, string* string, int mult);
char* capitalize(char* input, string* string, int punc);
char* swapcase(char* input, string* string, int punc);
char* title(char* input, string* string, int punc);
int istitle(char* input, string* string, int punc);
char* lower(char* input, string* string, int punc);
char* upper(char* input, string* string, int punc);
int islower(char* input, string* string, int punc);
int isupper(char* input, string* string, int punc);
int isalpha(char* input, string* string, int punc);
int isalnum(char* input, string* string, int punc);
int isspace(char* input, string* string, int punc);
char* lstrip(char* input, string* string, int punc);
char* rstrip(char* input, string* string, int punc);
char* name(char* input, string* string, int punc);
int equalname(char* tempname, string* string);
int overlap(string* string, char* input, int equal, int i);


int main(void)
{
	printf("[Simple Python Interpreter implemented by C]\n");

	int i = 0;
	int j, k = 0;
	char temp;
	int equal = 0;
	int plus=0, mult=0;
	int first, second;
	int method = 0;
	int punc = 0;
	int checkname;
	string* input;
	char* edit, *operation;
	edit = (char*)malloc(sizeof(char) * 100);
	operation = (char*)malloc(sizeof(char) * 100);
	char* print;
	int printcheck = 0;
	input = (string*)malloc(sizeof(string) * 20);
	char*casehandling = (char*)malloc(sizeof(char) * 100);
	char* tempname = (char*)malloc(sizeof(char) * 100);

	for (j = 0;j < 20;j++)
	{
		input[j].name = (char*)malloc(sizeof(char) * 100);
		input[j].content = (char*)malloc(sizeof(char) * 100);
	}

	while (1) {
		equal = 0;
		plus=0;
		mult = 0;
		k = 0;
		method = 0;
		printf(">>> ");
		punc = -1;

		for (j = 0;j < strlen(operation);j++)
			operation[j] = '\0';
		for (j = 0;j < strlen(tempname);j++)
			tempname[j] = '\0';

		scanf("%[^\n]s", operation);
		getchar();

		for (j = 0; j < strlen(operation); j++)
		{
			if (operation[j] == '=')
				equal = j;
			if (operation[j] == '+')
				plus = j;
			if (operation[j] == '*')
				mult = j;
			if (operation[j] == '('&&operation[j + 1] == ')')
				method = j;
		}

		if (equal == 0 && plus == 0 && mult == 0 && method == 0)
		{
			for (j = 0;j < 20;j++)
			{
				if (strcmp(input[j].name, operation) == 0)
				{
					printf("'%s'\n", input[j].content);
					break;
				}
			}

			if((operation[0]==34&&operation[strlen(operation)-1]!=34) || (operation[0] == 39 && operation[strlen(operation) - 1] != 39))
				printf("SyntaxError: EOL while scanning string literal\n");

			else if ((operation[0] != 34 && operation[strlen(operation) - 1] == 34) || (operation[0] != 39 && operation[strlen(operation) - 1] == 39))
				printf("SyntaxError: EOL while scanning string literal\n");

			else if ((operation[0] == 34 && operation[strlen(operation) - 1] == 34) || (operation[0] == 39 && operation[strlen(operation) - 1] == 39))
			{
				printf("'");
				for (j = 1;j < strlen(operation) - 1;j++)
					printf("%c", operation[j]);
				printf("'\n");
			}

			else if (j == 20 && operation[0]!='\0')
				printf("NameError: name '%s' is not defined\n", operation);
		}

		if (equal > 0)
		{
			if ((operation[equal + 2] == 39 && operation[strlen(operation) - 1]==39)|| (operation[equal + 2] == 34 && operation[strlen(operation) - 1] == 34))
			{
				for (j = 0; j < equal - 1; j++)
				{
					tempname[k++] = operation[j];
				}
				tempname[k] = '\0';
				k = 0;

				checkname = equalname(tempname, input);

				if (checkname >= 0)
				{
					for (j = equal + 3; j < strlen(operation) - 1; j++)
					{
						input[checkname].content[k++] = operation[j];
					}
					input[checkname].content[k] = '\0';
				}

				else if(checkname < 0)
				{
					for (j = 0; j < equal - 1; j++)
					{
						input[i].name[k++] = operation[j];
					}
					input[i].name[k] = '\0';
					k = 0;



					for (j = equal + 3; j < strlen(operation) - 1; j++)
					{
						input[i].content[k++] = operation[j];
					}
					input[i].content[k] = '\0';
					k = 0;

					i++;
				}
			}

			else if ((operation[equal + 2] == 39 && operation[strlen(operation) - 1] != 39) || (operation[equal + 2] == 34 && operation[strlen(operation) - 1] != 34))
			{
				printf("SyntaxError: EOL while scanning string literal\n");
			}

			else if ((operation[equal + 2] != 39 && operation[strlen(operation) - 1] == 39) || (operation[equal + 2] != 34 && operation[strlen(operation) - 1] == 34))
			{
				printf("SyntaxError: EOL while scanning string literal\n");
			}

			else if ((operation[equal + 2] != 39 && operation[strlen(operation) - 1] != 39) || (operation[equal + 2] != 34 && operation[strlen(operation) - 1] != 34))
			{
				if (operation[equal + 2] == '\0' || operation[equal + 2] == ' ')
					printf("SyntaxError: invalid syntax\n");

				else if (operation[0] == ' '&& equal == 1)
					printf("IndentationError: unexpected indent\n");

				else
				{
					for (j = equal + 2; j <= strlen(operation) - 1; j++)
					{
						tempname[k++] = operation[j];
					}
					tempname[k] = '\0';

					for (j = 0;j < 20;j++)
					{
						if (strcmp(tempname, input[j].name) == 0)
							break;
					}


					if (j == 20)
						printf("NameError: name '%s' is not defined\n", tempname);
					else
					{
						i = overlap(input, operation, equal, i);
					}
				}
				
				
			}

		}

		else if (plus>0)
		{
			if (operation[plus + 2] == '\0'|| operation[plus + 2] == ' ')
				printf("SyntaxError: invalid syntax\n");
			
			else if (operation[0] == ' '&& plus == 1)
				printf("IndentationError: unexpected indent\n");
			else
			{
				print = plusreturn(operation, input, plus);
				printf("%s\n", print);
				printcheck++;
			}
		}

		else if (mult>0)
		{
			if (operation[mult + 2] == '\0' || operation[mult + 2] == ' ')
				printf("SyntaxError: invalid syntax\n");
			
			else if (operation[0] == ' '&& mult == 1)
				printf("IndentationError: unexpected indent\n");
			else
			{
				print = multreturn(operation, input, mult);
				printf("%s\n", print);
				printcheck++;
			}
		}

		else if (method > 0)
		{
			if (strcmp("exit()", operation) == 0)
			{
				break;
			}
			
			for (k = 0; k < strlen(operation); k++)
			{
				if (operation[k] == '.')
				{
					punc = k;
					break;
				}
			}
			j = 0;

			if (punc == 0)
			{
				printf("SyntaxError: invalid syntax\n");
				continue;
			}

			else if (punc < 0)
			{
				for (k = 0;k <= strlen(operation) - 3;k++)
					casehandling[j++] = operation[k];
				casehandling[j] = '\0';
				printf("NameError: name '%s' is not defined\n", casehandling);
				continue;
			}

			j = 0;
			for (k = punc + 1; k <= strlen(operation) - 3; k++)
				casehandling[j++] = operation[k];
			casehandling[j] = '\0';

			if (strcmp(casehandling, "capitalize") == 0)
			{
				print = capitalize(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else if (strcmp(casehandling, "swapcase") == 0)
			{
				print = swapcase(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else if (strcmp(casehandling, "title") == 0)
			{
				print = title(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else if (strcmp(casehandling, "istitle") == 0)
			{
				if (istitle(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (istitle(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "lower") == 0)
			{
				print = lower(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}
			
			else if (strcmp(casehandling, "upper") == 0)
			{
				print = upper(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else if (strcmp(casehandling, "islower") == 0)
			{
				if (islower(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (islower(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "isupper") == 0)
			{
				if (isupper(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (isupper(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "isalpha") == 0)
			{
				if (isalpha(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (isalpha(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "isalnum") == 0)
			{
				if (isalnum(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (isalnum(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "isdigit") == 0)
			{
				if (isdigit(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (isdigit(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "isspace") == 0)
			{
				if (isspace(operation, input, punc) == 0)
				{
					printf("False\n");
				}
				else if (isspace(operation, input, punc) == 1)
				{
					printf("True\n");
				}
				else if (istitle(operation, input, punc) == 2)
				{
					print = name(operation, input, punc);
					printf("NameError: name '%s' is not defined\n", print);
					printcheck++;

				}
			}

			else if (strcmp(casehandling, "lstrip") == 0)
			{
				print = lstrip(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else if (strcmp(casehandling, "rstrip") == 0)
			{
				print = rstrip(operation, input, punc);
				printf("%s\n", print);
				printcheck++;

			}

			else
			{
				printf("AttributeError: 'str' object has no attribute '%s'\n", casehandling);
			}

		}
	}

	free(input);
	free(edit);
	free(operation);
	if(printcheck!=0)
		free(print);
	free(casehandling);
	free(tempname);

	return 0;
}


char* plusreturn(char* input, string* string, int plus)
{
	char* ret = (char*)malloc(sizeof(char)*100);
	char* first = (char*)malloc(sizeof(char) * 100);
	char* second = (char*)malloc(sizeof(char) * 100);
	int i;
	int firstnumb, secondnumb;

	strncpy(first, input, plus - 1);
	first[plus - 1] = '\0';
	strncpy(second, input + plus + 2, strlen(input) - plus - 2);
	second[strlen(input) - plus - 2] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			firstnumb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);
		free(second);

		return ret;
	}

	for (i = 0; i < 20; i++)
	{
		if (strcmp(second, string[i].name) == 0)
		{
			secondnumb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, second);
		strcat(ret, "' is not defined");
		free(first);
		free(second);

		return ret;
	}
	ret[0] = 39;
	strcpy(ret+1, string[firstnumb].content);
	strcat(ret, string[secondnumb].content);
	strcat(ret, "'");

	free(first);
	free(second);
	return ret;
}

char* multreturn(char* input, string* string, int mult)
{
	char* ret = (char*)malloc(sizeof(char) * 10000);
	char* first = (char*)malloc(sizeof(char) * 100);
	int numb;
	int numlength = 0;
	int i;
	int num=0;

	strcpy(first, input);
	first[mult - 1] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);

		return ret;
	}

	for (i = mult + 2; input[i]!='\0'; i++)
	{
		if (input[i] >= '0'&&input[i] <= '9')
			numlength++;
	}

	for (i = 0; i < numlength; i++)
	{
		num = num * 10 + (input[mult + 2 + i] - '0');
	}

	ret[0] = 39;
	strcpy(ret+1, string[numb].content);

	for (i = 1; i < num; i++)
	{
		strcat(ret, string[numb].content);
	}
	strcat(ret, "'");

	free(first);

	return ret;
}

char* capitalize(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char*ret = (char*)malloc(sizeof(char)*100);
	
	int numb;

	strncpy(first, input, punc);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(string[i].name, first)==0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);

		return ret;
	}

	ret[0] = 39;
	strcpy(ret+1, string[numb].content);

	if(ret[1]>='a'&& ret[1]<='z')
		ret[1] -= 32;

	strcat(ret, "'");

	free(first);

	return ret;
}

char* swapcase(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	int numb;
	char* temp = (char*)malloc(sizeof(char) * 100);

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(string[i].name, first) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(temp, "NameError: name '");
		strcat(temp, first);
		strcat(temp, "' is not defined");
		free(first);

		return temp;
	}
	temp[0] = 39;
	strcpy(temp+1, string[numb].content);

	for (i = 1; i < strlen(string[numb].content)+1; i++)
	{
		if (temp[i] >= 'a'&&temp[i] <= 'z')
			temp[i] -= 32;

		else if (temp[i] >= 'A'&&temp[i] <= 'Z')
			temp[i] += 32;
	}
	strcat(temp, "'");

	free(first);

	return temp;
}

char* title(char* input, string* string, int punc)
{
	int i;
	int numb;
	char* ret = (char*)malloc(sizeof(char) * 100);
	char* first = (char*)malloc(sizeof(char) * 100);

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(string[i].name, first) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);

		return ret;
	}
	ret[0] = 39;
	strcpy(ret+1, string[numb].content);

	if (ret[1] >= 'a'&&ret[1] <= 'z')
		ret[1] -= 32;

	for (i = 2; i < strlen(ret)+1; i++)
	{
		if (ret[i - 1] >= 'A'&&ret[i - 1] <= 'Z')
		{
			if (ret[i] >= 'A'&& ret[i] <= 'Z')
				ret[i] += 32;
		}

		else if (ret[i - 1] < 'A' || (ret[i - 1] > 'Z' && ret[i - 1]<'a') || (ret[i - 1]>'z'))
		{
			if (ret[i] >= 'a'&&ret[i] <= 'z')
				ret[i] -= 32;
		}

		else if (ret[i - 1] >= 'a'&&ret[i - 1] <= 'z')
		{
			if (ret[i] >= 'A'&&ret[i] <= 'Z')
				ret[i] += 32;
		}
	}
	strcat(ret, "'");

	free(first);

	return ret;
}

int istitle(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	int numb;
	char* cont = (char*)malloc(sizeof(char) * 100);
	int space=0;
	int true = 0;
	int upper = 0;

	strncpy(first, input,punc);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		free(first);
		free(cont);

		return 2;
	}

	strcpy(cont, string[numb].content);

	for (i = 0; i < strlen(cont); i++)
	{
		if (cont[i] < 'A' || (cont[i] > 'Z' && cont[i]<'a')|| (cont[i]>'z'))
			space++;
	}

	true = space;

	if (cont[0] >= 'a'&&cont[0] <= 'z')
		true--;

	for (i = 1; i < strlen(cont); i++)
	{
		if (cont[i - 1] >= 'A'&&cont[i - 1] <= 'Z')
		{
			if (cont[i] >= 'A'&& cont[i] <= 'Z')
				true--;
		}

		else if (cont[i-1] < 'A' || (cont[i-1] > 'Z' && cont[i-1]<'a') || (cont[i-1]>'z'))
		{
			if (cont[i] >= 'a'&&cont[i] <= 'z')
				true--;
		}

		else if (cont[i - 1] >= 'a'&&cont[i - 1] <= 'z')
		{
			if (cont[i] >= 'A'&&cont[i] <= 'Z')
				true--;
		}
	}

	for (i = 0;i < strlen(cont);i++)
	{
		if (cont[i] >= 'A'&&cont[i] <= 'Z')
			upper++;
	}

	free(first);
	free(cont);

	if (upper == 0)
		return 0;

	if (true < space)
		return  0;
	else
		return 1;
}

char* lower(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);

	int numb;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);

		return ret;
	}

	ret[0] = 39;
	strcpy(ret+1, string[numb].content);

	for (i = 1; i < strlen(ret)+1; i++)
	{
		if (ret[i] >= 'A'&&ret[i] <= 'Z')
			ret[i] += 32;
	}
	strcat(ret, "'");

	free(first);

	return ret;
}

char* upper(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);

		return ret;
	}

	ret[0] = 39;
	strcpy(ret+1, string[numb].content);

	for (i = 1; i < strlen(ret)+1; i++)
	{
		if (ret[i] >= 'a'&&ret[i] <= 'z')
			ret[i] -= 32;
	}
	strcat(ret, "'");

	free(first);

	return ret;
}

int islower(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;
	int check = 0;
	int lower = 0;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i] >= 'A'&&ret[i] <= 'Z')
			check++;
		if (ret[i] >= 'a'&&ret[i] <= 'z')
			lower++;
	}
	
	if (lower == 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}

int isupper(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;
	int check = 0;
	int higher = 0;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}

	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i] >= 'a'&&ret[i] <= 'z')
			check++;
		if (ret[i] >= 'A'&&ret[i] <= 'Z')
			higher++;
	}

	if (higher == 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}

int isalpha(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;
	int check = 0;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i]<'A' || (ret[i]>'Z' && ret[i]<'a') || ret[i]>'z')
			check++;
	}

	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}

int isalnum(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;
	int check = 0;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i]<'0'||ret[i]>'9' && ret[i]<'A' || (ret[i]>'Z' && ret[i]<'a') || ret[i]>'z')
			check++;
	}

	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}


int isdigit(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);

	int numb;
	int check = 0;

	strcpy(first, input);
	first[punc] = '\0';

	
	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i]<'0' || ret[i]>'9')
			check++;
	}

	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}

int isspace(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	int numb;
	int check = 0;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		free(first);
		free(ret);
		return 2;
	}

	strcpy(ret, string[numb].content);

	for (i = 0; i < strlen(ret); i++)
	{
		if (ret[i]!=' ')
			check++;
	}

	if (check > 0)
	{
		free(first);
		free(ret);
		return 0;
	}
	else
	{
		free(first);
		free(ret);
		return 1;
	}
}

char* lstrip(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	char* cont = (char*)malloc(sizeof(char) * 100);

	int numb;
	int pnt = -1;

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		
		free(first);
		free(cont);

		return ret;
	}

	ret[0] = 39;
	strcpy(cont, string[numb].content);

	for (i = 0; i < strlen(cont); i++)
	{
		if (cont[i] != ' ')
		{
			pnt = i;
			break;
		}
	}

	if (pnt >= 0)
	{
		strcpy(ret+1, cont + pnt);
		ret[strlen(cont) - pnt+1] = '\0';
		strcat(ret, "'");
	}

	else
	{
		strcpy(ret+1, "");
		strcat(ret, "'");
	}

	free(first);
	free(cont);

	return ret;
}

char* rstrip(char* input, string* string, int punc)
{
	int i;
	char* first = (char*)malloc(sizeof(char) * 100);
	char* ret = (char*)malloc(sizeof(char) * 100);
	char* cont = (char*)malloc(sizeof(char) * 100);
	int numb;
	int pnt;
	

	strcpy(first, input);
	first[punc] = '\0';

	for (i = 0; i < 20; i++)
	{
		if (strcmp(first, string[i].name) == 0)
		{
			numb = i;
			break;
		}
	}
	if (i == 20)
	{
		strcpy(ret, "NameError: name '");
		strcat(ret, first);
		strcat(ret, "' is not defined");
		free(first);
		free(cont);
		return ret;
	}

	ret[0] = 39;
	strcpy(cont, string[numb].content);
	pnt = strlen(cont);

	for (i = strlen(cont)-1; i>=0; i--)
	{
		if (cont[i] != ' ')
		{
			pnt = i;
			break;
		}
	}

	if (pnt <= strlen(cont) - 1)
	{
		strcpy(ret+1, cont);
		ret[pnt+2] = '\0';
		strcat(ret, "'");
	}

	else
	{
		strcpy(ret+1, "");
		strcat(ret, "'");
	}

	free(first);
	free(cont);

	return ret;
}

char* name(char* input, string* string, int punc)
{
	char* first = (char*)malloc(sizeof(char) * 100);

	strcpy(first, input);
	first[punc] = '\0';

	return first;
}

int equalname(char* tempname, string* string)
{
	int i;
	int ret=-1;

	for (i = 0;i < 20;i++)
	{
		if (strcmp(tempname, string[i].name) == 0)
		{
			ret = i;
			break;
		}
	}

	return ret;
}

int overlap(string* string, char* input, int equal, int i)
{
	int j,k=0;
	char* tempname = (char*)malloc(sizeof(char) * 100);
	int checkname;
	int secondname;

	for (j = 0; j < equal - 1; j++)
	{
		tempname[k++] = input[j];
	}
	tempname[k] = '\0';
	k = 0;

	checkname = equalname(tempname, string);

	for (j = equal + 2; j <= strlen(input) - 1; j++)
	{
		tempname[k++] = input[j];
	}
	tempname[k] = '\0';
	k = 0;

	secondname = equalname(tempname, string);

	if (checkname >= 0)
	{
		strcpy(string[checkname].content, string[secondname].content);
		string[checkname].content[strlen(string[secondname].content)] = '\0';

	}

	else if (checkname < 0)
	{
		for (j = 0; j < equal - 1; j++)
		{
			string[i].name[k++] = input[j];
		}
		string[i].name[k] = '\0';
		k = 0;

		strcpy(string[i].content, string[secondname].content);
		string[i].content[strlen(string[secondname].content)] = '\0';

		i++;
	}
	free(tempname);
		return i;
}