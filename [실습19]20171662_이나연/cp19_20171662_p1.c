#include <stdio.h>

typedef struct node* nptr;

typedef struct node {
	int data;
	nptr link;
}NODE;

void Insert(nptr*, int);
void PrintAll(nptr);

int main(void)
{
	int A[10] = {3,9,8,2,5,10,7,1,4,6 };

	NODE* list;
	list = (NODE*)malloc(sizeof(NODE));
	list->data = NULL;
	list->link = NULL;
	
	for (int i = 0;i < 10;i++)
		Insert(&list, A[i]);

	PrintAll(list);

	return 0;
}

void Insert(nptr* cur, int input)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = input;
	newNode->link = NULL;

	
		NODE* travel = NULL;
		for (travel = *cur;travel->link != NULL;travel = travel->link);
		travel->link = newNode;
	
}

void PrintAll(nptr cur)
{
	int i;

	for (i = 0;i < 10;i++)
	{
		printf("%d ", cur->link->data);
		cur = cur->link;
	}
		
}