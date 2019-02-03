#include <stdio.h>
#include <stdlib.h>

int string_length(char *st);

int main(void)
{
	char s[] = "C is a high-level language";
	char *t = "C프로그래밍";

	printf("문자열 s의 길이 : %d\n", string_length(s));
	//이 때에는 문자열 그대로의 길이를 나타낸다.
	printf("sizeof(s)       : %d\n", (int)sizeof(s));
	//이 때에는 애초에 정적 배열로 선언을 하였기 때문에 배열의 크기를 나타낸 것이다. 그러나 위와 다른 결과가 나온 이유는 이 때에는 NULL인 것까지도 다 세기 때문이다.
	printf("문자열 t의 길이 : %d\n", string_length(t));
	//한글의 바이트 수가 3이므로 1+3*5로 16이 나온다.
	printf("sizeof(t)       : %d\n", (int)sizeof(t));
	//이 때에는 애초에 동적 배열로 선언을 했기 땝문에 포인터 변수 자체의 크기를 나타낸 것이다.
	return 0;
}


int string_length(char *st)
{
	int i=0;

	while(st[i] != '\0')
	{
		i++;
	}

	return i;
}
