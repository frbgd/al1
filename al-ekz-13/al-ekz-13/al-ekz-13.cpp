#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main()
{
	double k, sign = -1;
	double n, sum = 0, eps = 10e-4;
	for (k = 1; ; k++)
	{
		sign *= -1;
		n = sign / k;
		if (fabs(n) < eps)
			break;
		else
			sum += n;
	}
	printf_s("k = %.0f\nn = %f\nsum = %f\n\n", k, n, sum);
	system("pause");
	return 0;
}