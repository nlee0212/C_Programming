#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _Node {
	int st_id;
	char *st_name;
	struct _Node *link;
}Node;

Node *head = NULL;

void create_Node(int id, char *name);

int main(void)
{
	int n;
	int i;
	int id;
	char* name;

	name = (char*)malloc(sizeof(char) * 30);
	
	FILE *fp;
	
	fp = fopen("input.txt", "r");

	fscanf(fp, "%d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%d / %[^\n]s", &id, name);
		create_Node(id, name);
	}

	for (i = 0; i < n; i++)
	{
		printf("%d / %s\n", head->st_id, head->st_name);
		head = head->link;
	}

	fclose(fp);
	free(name);
}

void create_Node(int id, char *name)
{
	Node *new;

	new = (Node*)malloc(sizeof(Node));
	new->st_name = (char*)malloc(sizeof(char) * 30);
	new->link = NULL;
	new->st_id=id;
	strcpy(new->st_name, name);
	
	if (head == NULL)
	{
		head = new;
	}
	
	else
	{
		Node* travel = NULL;
		for (travel = head; travel->link != NULL; travel = travel->link);
		travel->link = new;
	}
}