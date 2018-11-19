#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	float X, Y;
	printf_s("X = "); scanf_s("%f", &X);
	printf_s("Y = "); scanf_s("%f", &Y);
	if ((Y <= (-pow(X + 1, 2) + 1)) && (Y >= (-sqrt(1 - pow(X + 1, 2)))))
		printf_s("+\n");
	else
		printf_s("-\n");
	system("pause");
}