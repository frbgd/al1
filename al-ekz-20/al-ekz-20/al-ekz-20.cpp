#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = -1;
	while (n < 1)
	{
		printf_s("n = ");
		scanf_s("%d", &n);
	}
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 201;
		printf_s("%3d ", arr[i]);
	}
	printf_s("\n");
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 9 == 1 || arr[i] % 9 == 2 || arr[i] % 9 == 5)
		{
			flag = true;
			printf_s("%3d ", arr[i]);
		}
	}
	if (flag == false)
		printf_s("-");
	printf_s("\n");
	delete[] arr;
	system("pause");
	return 0;
}