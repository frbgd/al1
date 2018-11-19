#include<stdio.h>
#include<stdlib.h>

int summa(int a, int b = 10, int c = 5)
{
	return a + b + c;
}

int main()
{
	int i = 2, j = 5, s1, s2, s3;
	s1 = summa(i, 2, j);
	s2 = summa(i, j);
	s3 = summa(i);
	printf_s("%d %d %d\n", s1, s2, s3);
	system("pause");
	return 0;
}