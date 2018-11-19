#include<stdlib.h>
#include<stdio.h>

int main()
{
	double R = 1e-4, K, S = 0, n;
	for (K = 1;; K++)
	{
		n = 1 / (K * (K + 1));
		if (n < R)
			break;
		else
			S += n;
	}
	printf_s("n = %lf\nS = %lf\n", n, S);
	system("pause");
	return 0;
}