#include <stdlib.h>
#include <stdio.h>

int MaxEl(int *arr, int len)
{
	int max = arr[0];
	for (int i = 1; i < len; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
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
	int **matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			matr[i][j] = rand() % 21 + (-10);
			printf_s("%3d ", matr[i][j]);
		}
		printf_s("\n");
	}
	printf_s("\n");
	int *maxarr = new int[n];
	for (int i = 0; i < n; i++)
	{
		maxarr[i] = MaxEl(matr[i], m);
		printf_s("MaxEl%d = %d\n",i, maxarr[i]);
	}
	delete[] *matr;
	delete[] maxarr;
	system("pause");
	return 0;
}