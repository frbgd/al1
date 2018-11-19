#include <stdio.h>
#include <conio.h>
#include <math.h>

int fact(int n)
{
	if (n == 1) return 1;
	else return n * fact(n - 1);
}

double getIElement(int n)
{
	return (double)fact(n) / pow(n, n);
}

int main()
{
	double eps, sum, t;
	int degree;
	int i;
	puts("Enter degree ");
	scanf_s("%d", &degree);
	eps = pow(10, -abs(degree));

	for (sum = 0, i = 1;; i++)
	{
		t = getIElement(i);
		if (t < eps) break;
		else sum += t;
	}
	printf("\n%5.16f", sum);

	_getch();
	return 0;
}