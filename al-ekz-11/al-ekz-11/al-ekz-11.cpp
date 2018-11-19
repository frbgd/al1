#include <stdio.h>
#include <stdlib.h>

int Sum(int* arr, int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}

void main()
{
	int n;
	printf_s("n = "); scanf_s("%d", &n);
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 21 + (-10);
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");
	int s = Sum(arr, n);
	printf_s("Sum = %d\n", s);
	delete[] arr;
	system("pause");
}

//rand() % 109 + (-37)