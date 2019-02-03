#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
	int data;
	struct node *link;
}NODE;

void Insert(NODE **, int);
void Delete(NODE**);
void PrintAll(NODE*);

int main(void)
{
	int i;

	int A[10] = { 3,9,8,2,5,10,7,1,4,6 };

	NODE* list;
	list = (NODE*)malloc(sizeof(NODE));
	//list->data = NULL;
	list->link = NULL;


	for (i = 0;i < 10;i++)
		Insert(&list, A[i]);

	for (i = 0;i < 10;i++)
	{
		Delete(&list);
		PrintAll(list);
	}

	free(list);

	return 0;
}

void Insert(NODE ** cur, int a)
{
	NODE* temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = a;
	temp->link = NULL;

	NODE* travel = NULL;
	for (travel = *cur;travel->link != NULL;travel = travel->link);
	travel->link = temp;
}

void Delete(NODE** cur)
{
	NODE* pCur;

	pCur = (*cur);
	*cur = pCur->link;

	free(pCur);
}

void PrintAll(NODE* list)
{
	NODE* travel;

	if (list->link == NULL)
		printf("Empty\n");

	else 
	{
		for (travel = list;travel->link != NULL;travel = travel->link)
		{
			printf("%d ", list->link->data);
			list = list->link;
		}

		printf("\n");
	}
	
}
