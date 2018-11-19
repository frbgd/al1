#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = -1;
	while (n <= 0)
	{
		printf_s("n = ");
		scanf_s("%d", &n);
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 21 + (-10);
		printf_s("%d  ", arr[i]);
	}
	printf_s("\n");
	int smin = arr[0] + arr[1];
	for (int i = 1; i < n - 1; i++)
	{
		if (arr[i] + arr[i + 1] < smin)
			smin = arr[i] + arr[i + 1];
	}
	printf_s("smin = %d\n", smin);
	delete[] arr;
	system("pause");
	return 0;
}