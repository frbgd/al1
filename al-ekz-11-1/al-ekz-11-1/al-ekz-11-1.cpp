#include<stdlib.h>
#include<stdio.h>

int Sum(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

void main()
{
	int n, m;
	int s = 0;
	printf_s("n = "); scanf_s("%d", &n);
	printf_s("m = "); scanf_s("%d", &m);
	int **matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 21 + (-10);
			printf_s("%4d ", matr[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	int *sumarr = new int[n];
	for (int i = 0; i < n; i++)
	{
		sumarr[i] = Sum(matr[i], m);
		printf("%4d ", sumarr[i]);
	}
	printf_s("\n");
	s = Sum(sumarr, n);
	printf_s("s = %d\n", s);
	delete[] matr;
	delete[] sumarr;
	system("pause");
}