#include <stdio.h>
#include <stdlib.h>

typedef struct node *sptr;

typedef struct {
	int count;
	sptr link;
}STACK;

typedef struct node {
	int data;
	sptr link;
}STACK_NODE;

void Exit(STACK*);
void Push(STACK*);
void Pop(STACK*);
void PrintAll(STACK);

int main(void)
{
	int select;
	int input;

	STACK stack;
	stack.count = 0;
	
	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Push       *\n");
	printf("* 2 : Pop        *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");

	while (1)
	{
		printf("Select > ");
		scanf("%d", &select);

		switch (select) {
		case 0: Exit(&stack); return 0; break;
		case 1: Push(&stack); break;
		case 2: Pop(&stack); break;
		case 3: PrintAll(stack); break;
		}
	}

	return 0;
}

void Exit(STACK* stack)
{
	int i,j;

		for (i = stack->count;i > 0;i--)
		{
			STACK_NODE* travel;
			travel = (STACK_NODE*)malloc(sizeof(STACK_NODE));
			travel = stack->link;
			
			travel = stack->link;

			for (j = 1;j < i;j++)
				travel = travel->link;

			free(travel);
		}
	

}

void Push(STACK* stack)
{
	int input;

	printf("Input Data > ");
	
	scanf("%d", &input);

	STACK_NODE *stnode;

	stnode = (STACK_NODE*)malloc(sizeof(STACK_NODE));

	stnode->data = input;
	stnode->link = NULL;

	if (stack->link == NULL)
		stack->link = stnode;

	else 
	{
		stnode->link = stack->link;
		stack->link = stnode;
		
	}

	stack->count++;
}

void Pop(STACK* stack)
{
	int pop;
	
	pop = stack->link->data;

	STACK_NODE *temp;
	temp = (STACK_NODE*)malloc(sizeof(STACK_NODE));

	if (stack->count == 0)
		printf("Stack is Empty!\n");
	
	else {
		temp = stack->link;

		stack->link = temp->link;

		free(temp);

		printf("Pop %d\n", pop);

		stack->count--;
	}
}

void PrintAll(STACK stack)
{
	int i=0,j;
	int* arr;
	int cnt=0;

	arr = (int*)malloc(sizeof(int) * 100);

	STACK_NODE* travel;
	travel = (STACK_NODE*)malloc(sizeof(STACK_NODE));
	travel = stack.link;

	if (stack.count == 0)
		printf("Stack is Empty!\n");

	else 
	{
		for (i = stack.count;i > 0;i--)
		{
			travel = stack.link;
			
			for (j = 1;j < i;j++)
				travel = travel->link;

			printf("%d ", travel->data);
		}

		printf("\n");

		printf("Stack Level : %d\n", stack.count);
	}
}