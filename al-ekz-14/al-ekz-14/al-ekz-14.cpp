#include<stdlib.h>
#include<stdio.h>

int main()
{
	double A = -1;
	while (A < 0)
	{
		printf_s("A = "); scanf_s("%lf", &A);
	}
	double f1 = 1, f2 = 1, fn;
	if (A == 0)
		fn = f1;
	else if (A == 1)
		fn = f1 + f2;
	else
	{
		fn = f1 + f2;
		do
		{
			f1 = f2;
			f2 = fn;
			fn = f1 + f2;
		} while (fn <= A);
	}
	printf_s("%.0lf\n", fn);
	system("pause");
	return 0;
}