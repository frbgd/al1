#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n = 0, k, s = 0;
	while (n < 1)
	{
		printf_s("n = ");
		scanf_s("%d", &n);
	}
	bool flag = false;
	for (int i = 1; i <= n; i++)
	{
		k = i * i*i - 3 * i*n*n + n;
		if ((k / 3) % 2 == 1)
		{
			s += k;
			flag = true;
		}
	}
	if (flag)
		printf_s("s = %d\n", s);
	else
		printf_s("-\n");
	system("pause");
	return 0;
}