#include <stdio.h>
#include <string.h>

typedef struct
{
	char name[20];
	char subject[20];
	int score;
}stu;

typedef union
{
	char name[20];
	char subject[20];
	int score;
}Student;

int main(void)
{
	stu a;

	Student first, second;
	
	scanf("%s %s %d", a.name, a.subject, &a.score);

	strcpy(first.name, a.name);
	strcpy(first.subject, a.subject);
	first.score = a.score;

	printf("Name      : %s\n", first.name);
	printf("Subject   : %s\n", first.subject);
	printf("Score     : %d\n", first.score);
	//union은 첫번째 변수에다가 메모리를 할당하기 때문에 연속으로 데이터를 저장하게 되면 첫번째 변수에 할당한 메모리에 나중에 저장한 데이터로 덧씌워지게 된다.

	strcpy(second.name, a.name);
	printf("Name      : %s\n", second.name);
	strcpy(second.subject, a.subject);
	printf("Subject   : %s\n", second.subject);
	second.score = a.score;
	printf("Score     : %d\n", second.score);
	//하지만 이번에는 저장하자마자 출력하기로 했으므로 덧씌워지기 전에 출력을 했기 때문에 결과가 이렇게 나오는 것이다.
	return 0;
}

