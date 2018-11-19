#include<stdlib.h>
#include<stdio.h>

double Average(double *arr, int len)
{
	double avg, sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	avg = (double)sum / len;
	return avg;
}

int main()
{
	int n = -1, m = -1;
	while (n < 1 || m < 1)
	{
		printf_s("n = ");
		scanf_s("%d", &n);
		printf_s("m = ");
		scanf_s("%d", &m);
	}
	double **matr = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new double[m];
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 201 + (-100);
			printf_s("%4.0lf ", matr[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	double *avgarr = new double[n];
	for (int i = 0; i < n; i++)
	{
		avgarr[i] = Average(matr[i], m);
		printf_s("avgarr%d = %.2lf\n", i, avgarr[i]);
	}
	delete[] * matr;
	delete[] avgarr;
	system("pause");
	return 0;
}