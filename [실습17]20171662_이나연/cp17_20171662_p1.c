#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
	char dept_name[25];
	int dept_no;
} dept;

enum Gender { Male = 0, Female };

typedef struct {
	int employee_id;
	char name[25];
	enum Gender gender;
	dept department;
	double salary;
}employee_data;

int search(employee_data *e, int num, int keyword);
employee_data update(employee_data e, int n);

int main(void)
{
	int n;
	int i;
	char temp;
	char last[25];
	int keyword;
	int deptno;
	char yn;
	int ret=0;
	char gen[10];

	employee_data *em;

	FILE *fp;

	fp = fopen("17_input.txt", "r");

	fscanf(fp, "%d", &n);

	em = (employee_data*)malloc(sizeof(employee_data)*n);

	for (i = 0;i < n;i++)
	{
		//last[0] = '\0';

		fscanf(fp, "%d / %s %s / %s / %s / %d / %lf", &(em[i].employee_id), &(em[i].name), last, gen, &em[i].department.dept_name, &em[i].department.dept_no, &em[i].salary);

		if (strcmp(gen,"Male")==0)
			em[i].gender = 0;
		else
			em[i].gender = 1;

		strcat(em[i].name, " ");
		strcat(em[i].name, last);
	}

	while(1) {
		printf("Employee ID : ");
		scanf("%d", &keyword);

		printf("------Employee Data------\n");

		for (i = 0; i < 10; i++)
			gen[i] = '\0';

		ret = search(em, n, keyword);

		if (em[ret].gender ==Male)
			strcpy(gen, "Male");
		else
			strcpy(gen, "Female");
		
		printf("%d / %s / %s / %s / %d / %.2lf\n", em[ret].employee_id, em[ret].name, gen, em[ret].department.dept_name, em[ret].department.dept_no, em[ret].salary);

		printf("------Update Information------\n");

		printf("Input the department Number : ");

		scanf("%d", &deptno);
		getchar();

		em[ret] = update(em[ret], deptno);

		printf("------Updated employee data------\n");

		printf("%d / %s / %s / %s / %d / %.2lf\n", em[ret].employee_id, em[ret].name, gen, em[ret].department.dept_name, em[ret].department.dept_no, em[ret].salary);

		printf("Continue? (y/n) : ");
		scanf("%c", &yn);

		if (yn == 'n')
			break;
	}
	
	fclose(fp);

	return 0;
}

int search(employee_data *e, int num, int keyword)
{
	int ret;
	int i;

	for (i = 0; i < num; i++)
	{
		if (e[i].employee_id == keyword)
			ret = i;
	}

	return ret;
}

employee_data update(employee_data e, int n)
{
	e.department.dept_no = n;

	switch (n) {
	case 1: strcpy(e.department.dept_name, "FINANCE"); break;
	case 2: strcpy(e.department.dept_name, "SALES"); break;
	case 3: strcpy(e.department.dept_name, "RESEARCH");	break;
	case 4: strcpy(e.department.dept_name, "PLANNING"); break;
	}
	return e;
}