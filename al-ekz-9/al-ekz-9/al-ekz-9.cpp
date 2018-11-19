#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

void main()
{
	float x, f;
	printf_s("x = "); scanf_s("%f", &x);
	if (x < 0)
		f = 0;
	else if (x < 1.5)
		f = pow((sin(x) + cos(x)), 2);
	else
		f = sin(x) - sqrt(x) + cos(M_PI * x * x);
	printf_s("f(x) = %f\n", f);
	system("pause");
}