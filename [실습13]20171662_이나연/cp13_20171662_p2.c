#include <stdio.h>

int main(void)
{
	struct exchange {
		int main, fh, h, ft, t;
	};

	struct exchange money;

	scanf("%d", &money.main);

	money.fh = money.main / 500;

	money.main -= money.fh * 500;

	money.h = money.main / 100;

	money.main -= money.h * 100;

	money.ft = money.main / 50;

	money.main -= money.ft * 50;

	money.t = money.main / 10;

	printf("%d\n%d\n%d\n%d\n", money.fh, money.h, money.ft, money.t);

	return 0;
}