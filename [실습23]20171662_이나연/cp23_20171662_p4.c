#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	char command[10];
	struct node* next;
} QUEUE_NODE;

typedef struct {
	QUEUE_NODE* front;
	int count;
	QUEUE_NODE* rear;
} QUEUE;

int CheckCommand(char* command);
void EnqueueCommand(QUEUE* pQueue, char* dataIn);
int DequeuePrint(QUEUE* pQueue, char* dataOut);
void quit(QUEUE* pQueue);

int main(void)
{
	int check, deq;
	int i;
	char* command;
	command = (char*)malloc(sizeof(char) * 10);
	char* dataOut;
	dataOut = (char*)malloc(sizeof(char) * 10);
	QUEUE* pQueue;
	pQueue = (QUEUE*)malloc(sizeof(QUEUE));

	pQueue->front = NULL;
	pQueue->count = 0;
	pQueue->rear = NULL;

	while (1)
	{
		printf(">>");
		scanf("%s", command);

		check = CheckCommand(command);

		if (check == 1 && strcmp(command, "history") == 0)
		{
			while (1)
			{
				strcpy(dataOut, pQueue->front->command);
				printf("%s\n", dataOut);

				deq = DequeuePrint(pQueue, dataOut);
				dataOut[0] = '\0';

				if (deq == 0)
					break;
			}
		}

		else if (check == 1 && strcmp(command, "h") == 0)
		{
			while (1)
			{
				strcpy(dataOut, pQueue->front->command);
				printf("%s\n", dataOut);

				deq = DequeuePrint(pQueue, dataOut);
				dataOut[0] = '\0';

				if (deq == 0)
					break;
			}
		}

		else if (check == 1 && strcmp(command, "quit") == 0)
		{
			quit(pQueue);
			return 0;
		}

		else if (check == 1 && strcmp(command, "q") == 0)
		{
			quit(pQueue);
			return 0;
		}

		else if (check == 1 && strcmp(command, "help") == 0)
		{
			EnqueueCommand(pQueue, command);
			printf("[Valid] %s\n", command);
		}

		else if (check == 1 && strcmp(command, "dir") == 0)
		{
			EnqueueCommand(pQueue, command);
			printf("[Valid] %s\n", command);
		}

		else if (check == 1 && strcmp(command, "mkdir") == 0)
		{
			EnqueueCommand(pQueue, command);
			printf("[Valid] %s\n", command);
		}

		else if (check == 1 && strcmp(command, "cd") == 0)
		{
			EnqueueCommand(pQueue, command);
			printf("[Valid] %s\n", command);
		}

		else if(check==0)
			printf("[Invalid]\n");
	}

	return 0;
}

int CheckCommand(char* command)
{
	if (strcmp(command, "help") == 0)
		return 1;
	else if (strcmp(command, "dir") == 0)
		return 1;
	else if (strcmp(command, "mkdir") == 0)
		return 1;
	else if (strcmp(command, "cd") == 0)
		return 1;
	else if (strcmp(command, "history") == 0)
		return 1;
	else if (strcmp(command, "h") == 0)
		return 1;
	else if (strcmp(command, "quit") == 0)
		return 1;
	else if (strcmp(command, "q") == 0)
		return 1;
	else
		return 0;
}

void EnqueueCommand(QUEUE* pQueue, char* dataIn)
{
	QUEUE_NODE* pNew;
	pNew = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
	strcpy(pNew->command, dataIn);
	pNew->next = NULL;

	if (pQueue->count == 0)
	{
		pQueue->front = pNew;
		pQueue->rear = pNew;
	}

	else
	{
		pQueue->rear = pNew;

		QUEUE_NODE* travel;
		travel = (QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
		travel = pQueue->front;

		for (int i = 1;i < pQueue->count;i++)
			travel = travel->next;

		travel->next = pNew;
	}

	pQueue->count++;
}

int DequeuePrint(QUEUE* pQueue, char* dataOut)
{
	if (pQueue->count == 0)
		return 0;

	else
	{
		QUEUE_NODE* travel;
		travel = pQueue->front;

		pQueue->front = travel->next;
		if (strcmp(dataOut, travel->command) == 0)
		{
			free(travel);
			pQueue->count--;
		}

		if (pQueue->count == 0)
			return 0;

		else if (pQueue->count > 0)
			return 1;
	}
}

void quit(QUEUE* pQueue)
{
	QUEUE_NODE* travel;

	if (pQueue->count == 1)
	{
		travel = pQueue->front;
		pQueue->front = NULL;
		pQueue->rear = NULL;
		free(travel);
	}

	else if (pQueue->count > 1)
	{
		for (int i = 1;i < pQueue->count;i++)
		{
			travel = pQueue->front;
			pQueue->front = travel->next;
			free(travel);
			QUEUE_NODE* travel;
		}
	}
}
