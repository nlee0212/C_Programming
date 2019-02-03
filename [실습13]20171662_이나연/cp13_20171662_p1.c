#include <stdio.h>

enum Date getDate(int y, int m, int d);
char* getDay(enum Date currDate);


int main(void)
{
	struct Calendar
	{
		int year, month, day;
		enum Date date;
		char* dateString;
	};

	struct Calendar cal;

	scanf("%d %d %d", &cal.year, &cal.month, &cal.day);

	cal.date = getDate(cal.year, cal.month, cal.day);

	cal.dateString = (char*)malloc(sizeof(char) * 10);

	cal.dateString = getDay(cal.date);

	printf("%s\n", cal.dateString);

	return 0;
}

enum Date getDate(int y, int m, int d)
{
	enum Date date;

	date = (y + y / 4 - y / 100 + y / 400 + (13 * m + 8) / 5 + d) % 7;

	return date;
}

char* getDay(enum Date currDate)
{
	char* day = (char*)malloc(sizeof(char) * 10);

	switch (currDate) {
	case 0: day = "Sunday";
		break;
	case 1: day = "Monday";
		break;
	case 2: day = "Tuesday";
		break;
	case 3: day = "Wednesday";
		break;
	case 4: day = "Thursday";
		break;
	case 5: day = "Friday";
		break;
	case 6: day = "Saturday";
		break;
	}

	return day;
}