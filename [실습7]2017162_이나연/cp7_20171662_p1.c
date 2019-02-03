#include <stdio.h>
#include <stdlib.h>

int *get_new_array(int size);
void get_new_array_call_by_value(int *a, int size);
void get_new_array_call_by_reference(int **a, int size);
void print_state(int *a);

int main(void)
{
	int *a = NULL;
	print_state(a);

	get_new_array_call_by_value(a,10);
	print_state(a);
	free(a);

	get_new_array_call_by_reference(&a, 10);
	print_state(a);
	free(a);

	a = get_new_array(10);
	print_state(a);
	free(a);
	return 0;
}

int *get_new_array(int size)
{
	int *array = (int *) malloc (sizeof(int)*size);

	return array;
}

void get_new_array_call_by_value(int *a, int size)
{
	a = (int *) malloc (sizeof(int)*size);
	// call by value로 값을 받으면 함수에서는 주소값이 아닌 그냥 a의 실제값을 받은 것이기 때문에 주소값에 메모리를 할당한 것이 아니게 된다.
}

void get_new_array_call_by_reference(int **a, int size)
{
	*a = (int *) malloc (sizeof(int)*size);
}

void print_state(int *a)
{
	if(a == NULL)
		printf("not allocated\n");

	else
		printf("allocated\n");
}


