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
	//union�� ù��° �������ٰ� �޸𸮸� �Ҵ��ϱ� ������ �������� �����͸� �����ϰ� �Ǹ� ù��° ������ �Ҵ��� �޸𸮿� ���߿� ������ �����ͷ� ���������� �ȴ�.

	strcpy(second.name, a.name);
	printf("Name      : %s\n", second.name);
	strcpy(second.subject, a.subject);
	printf("Subject   : %s\n", second.subject);
	second.score = a.score;
	printf("Score     : %d\n", second.score);
	//������ �̹����� �������ڸ��� ����ϱ�� �����Ƿ� ���������� ���� ����� �߱� ������ ����� �̷��� ������ ���̴�.
	return 0;
}

