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
	int count;
	QUEUE_NODE* rear;
}QUEUE;

void Exit(QUEUE*);
void Enqueue(QUEUE*);
void PrintAll(QUEUE);
void Dequeue(QUEUE*);

int main(void)
{
	int select;
	QUEUE queue;
	queue.count = 0;
	queue.front = NULL;
	queue.rear = NULL;
	
	printf("****** Menu ******\n");
	printf("* 0 : Exit       *\n");
	printf("* 1 : Enqueue    *\n");
	printf("* 2 : Dequeue    *\n");
	printf("* 3 : Print All  *\n");
	printf("******************\n");

	while (1)
	{
		printf("Select > ");
		scanf("%d", &select);

		switch (select) {
		case 0: Exit(&queue); return 0; break;
		case 1: Enqueue(&queue); break;
		case 2: Dequeue(&queue); break;
		case 3: PrintAll(queue); break;
		}
	}

	return 0;
}

void Exit(QUEUE* pQueue)
{
	int i;
	
	for (i = 1;i < pQueue->count;i++)
	{
		QUEUE_NODE* travel;
		travel = pQueue->front;

		pQueue->front = travel->next;
		free(travel);
	}
}

void Enqueue(QUEUE* pQueue)
{
	int input;
	int i;
	QUEUE_NODE* pNew;
	pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	
	printf("Input Data > ");
	scanf("%d", &input);

	pNew->data = input;
	pNew->next = NULL;

	if (pQueue->count == 0)
	{
		pQueue->front = pNew;
		pQueue->rear = pNew;
	}

	else
	{
		QUEUE_NODE* travel;
		travel = pQueue->front;

		for (i = 1;i < pQueue->count;i++)
			travel = travel->next;

		travel->next = pNew;
		pQueue->rear = pNew;
	}

	pQueue->count++;
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

void Dequeue(QUEUE* pQueue)
{
	int i;
	QUEUE_NODE* travel;
	int dequeue;
	
	if (pQueue->count == 0)
		printf("Queue is Empty!\n");
	else if (pQueue->count == 1)
	{
		travel = pQueue->front;
		dequeue = travel->data;
		pQueue->front = NULL;
		pQueue->rear = NULL;
		free(travel);
		pQueue->count--;
	}
	else
	{
		QUEUE_NODE* travel;
		travel = pQueue->front;
		dequeue = travel->data;
		pQueue->front = travel->next;
		free(travel);
		pQueue->count--;
	}

	printf("Dequeue %d\n", dequeue);
}

