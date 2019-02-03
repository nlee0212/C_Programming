#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;

typedef struct {
	int count;
	nptr link;
}STACK;

typedef struct node {
	char data;
	nptr link;
}STACK_NODE;

void Push(STACK*, char);
int Pop(STACK*);

int main(void)
{
	STACK stack;
	stack.count = 0;
	stack.link = NULL;

	char* input;
	int i,j;
	int cnt=0;

	input = (char*)malloc(sizeof(char) * 100);

	scanf("%s", input);

	for (i = 0;i < 100;i++)
	{
		if (input[i] == '(')
		{
			Push(&stack, '(');
			for (j = i;j < 100;j++)
			{
				if (input[j] == ')')
					Pop(&stack);
			}
		}

		if (input[i] == '[')
		{
			Push(&stack, '[');
			for (j = i;j < 100;j++)
			{
				if (input[j] == ']')
					Pop(&stack);
			}
		}

		if (input[i] == '{')
		{
			Push(&stack, '{');
			for (j = i;j < 100;j++)
			{
				if (input[j] == '}')
					Pop(&stack);
			}
		}

		if (stack.count < 0)
			cnt++;

		if (cnt > 0)
			return 0;
	}

	if (stack.count == 0)
		printf("Matched Parentheses!\n");
	else if (stack.count > 0)
		printf("Unmatched Parentheses!\n");

	return 0;
}

void Push(STACK* pStack, char par)
{
	STACK_NODE* pNew;

	pNew = (STACK_NODE*)malloc(sizeof(STACK_NODE));

	pNew->data = par;
	pNew->link = NULL;

	if (pStack->link == NULL)
		pStack->link = pNew;

	else
	{
		pNew->link = pStack->link->link;
		pStack->link = pNew;
	}

	pStack->count++;
}

int Pop(STACK* pStack)
{
	if (pStack->count == 0)
		printf("Unmatched Parentheses!\n");

	else
	{
		STACK_NODE* temp;

		temp = (STACK_NODE*)malloc(sizeof(STACK_NODE));

		temp = pStack->link;

		pStack->link = temp->link;
		free(temp);
	}

	pStack->count--;
}