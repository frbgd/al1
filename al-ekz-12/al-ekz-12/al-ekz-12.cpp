#include<stdio.h>
#include<stdlib.h>

int main()
{
	int k = -1;
	double f1 = 1, f2 = 1;
	double fn = f1 + f2;
	double sum;
	do {
		printf_s("k = "); scanf_s("%d", &k);
	} while (k < 0);
	if (k == 0)
		sum = 0;
	else if (k == 1)
	{
		sum = f1;
		printf_s("1: %.0f\n", f1);
	}
	else if (k == 2)
	{
		sum = f1 + f2;
		printf_s("1: %.0f\n2: %.0f\n", f1, f2);
	}
	else
	{
		sum = f1 + f2 + fn;
		printf_s("1: %.0f\n2: %.0f\n3: %.0f\n", f1, f2, fn);
		for (int i = 3; i < k; i++)
		{
			f1 = f2;
			f2 = fn;
			fn = f1 + f2;
			sum += fn;
			printf_s("%d: %.0f\n", i + 1, fn);
		}
	}
	printf_s("sum = %.0f\n", sum);
	system("pause");
	return 0;
}