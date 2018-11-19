#include<stdlib.h>
#include<stdio.h>

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
		arr[i] = rand() % 156;
		printf_s("%3d ", arr[i]);
	}
	printf_s("\n");
	bool flag = false;
	for(int i = 0; i < n; i++)
		if (arr[i] % 7 == 1 || arr[i] % 7 == 2 || arr[i] % 7 == 5)
		{
			flag = true;
			printf_s("%3d ", arr[i]);
		}
	if (flag == false)
		printf_s("-");
	printf_s("\n");
	delete[] arr;
	system("pause");
	return 0;
}