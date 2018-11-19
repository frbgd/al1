#include <stdlib.h>
#include<stdio.h>

struct mybitfields
{
	unsigned short a : 4;
	unsigned short b : 5;
	unsigned short c : 7;
} test;

int main()
{
	test.a = 2;				//2 = 0010 = 2
	test.b = 32;			//32 = 100000 but length(test.b) = 5bit => 00000 = 0
	test.c = 177;			//177 = 10110001 but length(test.b) = 7bit => 0110001 = 49
	printf_s("%d %d %d\n", test.a, test.b, test.c);
	system("pause");
	return 0;
}