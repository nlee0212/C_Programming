#include <stdio.h>
#include <stdlib.h>

typedef struct node*nptr;
typedef struct node
{
	char data;
	nptr link;
}NODE;

nptr head = NULL;

void DeleteNodeAtFront();
void DeleteNodeAtBack();
void InsertNodeAtFront(char);
void InsertNodeAtBack(char);
void PrintList();

int main(void)
{
	InsertNodeAtFront('n');
	InsertNodeAtFront('e');
	InsertNodeAtFront('p');
	InsertNodeAtBack('l');
	InsertNodeAtFront('o');
	InsertNodeAtBack('a');
	InsertNodeAtBack('b');
	PrintList();
	DeleteNodeAtFront();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	DeleteNodeAtBack();
	PrintList();

	return 0;
}

void DeleteNodeAtFront()
{
	NODE* pPre;

	pPre = head;
	head = pPre->link;

	free(pPre);
}

void DeleteNodeAtBack()
{
	NODE* pPre=head;
	NODE* travel = head;
	
	for (travel = head;travel->link != NULL;travel = travel->link)
		pPre = travel;
	
	pPre->link = travel->link;
	free(travel);
}

void InsertNodeAtFront(char a)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = a;
	newNode->link = head;

	head = newNode;
}

void InsertNodeAtBack(char b)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->data = b;
	newNode->link = NULL;

	NODE* travel = NULL;
	for (travel = head;travel->link != NULL;travel = travel->link);
	travel->link = newNode;
}

void PrintList()
{
	NODE* temp;

	for (temp = head;temp != NULL;temp = temp->link)
		printf("%c", temp->data);

	printf("\n");
}