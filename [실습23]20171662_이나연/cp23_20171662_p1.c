#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}QUEUE_NODE;

typedef struct
{
	QUEUE_NODE* front;
	int			count;
	QUEUE_NODE* rear;
}QUEUE;

void Exit(QUEUE*);
void Enqueue(QUEUE*);
void PrintAll(QUEUE);

int main(void)
{
	QUEUE queue;
	queue.count = 0;
	queue.front = NULL;
	queue.rear = NULL;

	int select;

	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Enqueue    *\n");
	printf("* 2 : -------    *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");

	while (1) {
		printf("Select > ");
		scanf("%d", &select);

		switch (select)
		{
		case 0: Exit(&queue); return 0; break;
		case 1: Enqueue(&queue);break;
		case 2: break;
		case 3: PrintAll(queue);break;
		}

	}
	
	return 0;
}

void Exit(QUEUE* queue)
{
	QUEUE_NODE* temp;
	int i;

	temp = queue->front;

	if (queue->count == 1)
		queue->rear = queue->front = NULL;
	else if(queue->count>1)
	{
		for (i = 0;i < queue->count;i++)
		{
			QUEUE_NODE* temp;
			temp = queue->front;
			queue->front = queue->front->next;
			free(temp);
		}
	}
}

void Enqueue(QUEUE* queue)
{
	int input;
	int i;

	printf("Input Data > ");
	scanf("%d", &input);

	QUEUE_NODE* pNew;
	pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	QUEUE_NODE* travel;
	travel = queue->front;

	pNew->data = input;
	pNew->next = NULL;

	if (queue->count == 0)
	{
		queue->front = pNew;
		queue->rear = pNew;
	}

	else
	{
		queue->rear = pNew;
		for (i = 1;i < queue->count;i++)
		{
			travel = travel->next;
		}
		travel->next = pNew;
	}

	queue->count++;
}

void PrintAll(QUEUE queue)
{
	int i;

	QUEUE_NODE* travel;
	travel = queue.front;

	for (i = 0;i < queue.count;i++)
	{
		printf("%d ", travel->data);
		travel = travel->next;
	}

	printf("\n");

	printf("Queue Level : %d\n", queue.count);
}
