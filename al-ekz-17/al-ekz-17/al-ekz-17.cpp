#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n = -1;
	while (n < 1)
	{
		printf_s("n = "); scanf_s("%d", &n);
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 201 + (-100);
		printf_s("%4d ", arr[i]);
	}
	printf_s("\n");
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
			number++;
	}
	printf_s("number = %d\n", number);
	delete[] arr;
	system("pause");
	return 0;
}