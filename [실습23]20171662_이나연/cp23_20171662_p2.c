#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char command[10];
	struct node* next;
}QUEUE_NODE;

typedef struct {
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
}QUEUE;

int CheckCommand(char* command);
void EnqueueCommand(QUEUE* pQueue, char* dataIn);

int main(void)
{
	int check;
	char command[10];
	QUEUE* pQueue;
	pQueue = (QUEUE*)malloc(sizeof(QUEUE));

	pQueue->front = NULL;
	pQueue->count = 0;
	pQueue->rear = NULL;

	while (1) {
		printf(">>");
		scanf("%s", command);

		check = CheckCommand(command);
		
		if (strcmp(command, "history") == 0 && check == 1)
		{
			printf("queue count = %d\n", pQueue->count);
			
		}
		else if (strcmp(command, "h") == 0 && check == 1)
		{
			printf("queue count = %d\n", pQueue->count);
			
		}
		else if (strcmp(command, "quit")==0 && check == 1)
			return 0;
		else if (strcmp(command, "q")==0 && check == 1)
			return 0;
		else if (check == 1)
		{
			printf("[Valid] %s\n", command);
			EnqueueCommand(pQueue, command);
		}
		else if (check == 0)
		{
			printf("[Invalid]\n");
		}
	}

	return 0;
}

int CheckCommand(char* command)
{
	if (strcmp(command, "help") == 0)
		return 1;

	else if ((strcmp(command, "dir") == 0))
		return 1;

	else if ((strcmp(command, "mkdir") == 0))
		return 1;

	else if ((strcmp(command, "cd") == 0))
		return 1;

	else if ((strcmp(command, "history") == 0))
		return 1;

	else if ((strcmp(command, "h") == 0))
		return 1;

	else if ((strcmp(command, "quit") == 0))
		return 1;

	else if ((strcmp(command, "q") == 0))
		return 1;

	else
		return 0;
}

void EnqueueCommand(QUEUE* pQueue, char* dataIn)
{
	int i;
	
	QUEUE_NODE* pNew;
	pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));

	strcpy(pNew->command, dataIn);
	pNew->next = NULL;

	QUEUE_NODE* temp;
	temp = pQueue->front;

	if (pQueue->count == 0)
	{
		pQueue->front = pNew;
		pQueue->rear = pNew;
	}

	else
	{
		for (i = 1;i < pQueue->count;i++)
		{
			temp = temp->next;
		}

		temp->next = pNew;
		pQueue->rear = pNew;
	}

	pQueue->count++;
}