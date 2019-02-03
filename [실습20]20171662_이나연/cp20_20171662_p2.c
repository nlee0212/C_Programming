#include <stdio.h>

void InsertNodeAtFront(char);
void InsertNodeAtBack(char);
void PrintList();

typedef struct _NODE{
	char DATA;
	struct _NODE *LINK;
}NODE;

NODE *head;

int main(void)
{
	char a, b;

	InsertNodeAtFront('p');
	InsertNodeAtFront('p');
	InsertNodeAtFront('a');
	InsertNodeAtBack('l');
	InsertNodeAtBack('e');
	PrintList();

	return 0;
}

void InsertNodeAtFront(char a)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->DATA = a;
	newNode->LINK = head;

	head = newNode;
}

void InsertNodeAtBack(char b)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->DATA = b;
	newNode->LINK = NULL;

	NODE* travel = NULL;
	for (travel = head;travel->LINK != NULL;travel = travel->LINK);
	travel->LINK = newNode;
}

void PrintList()
{
	NODE* temp;
	
	for (temp = head;temp != NULL;temp=temp->LINK)
		printf("%c", temp->DATA);

	printf("\n");
}