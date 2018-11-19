#include<stdio.h>
#include<stdlib.h>

int func(int k)
{
	k *= 2;
	return k;
}

int funclink(int &k)
{
	k *= 2;
	return k;
}

int main()
{
	int z = 1, y = 3, k;
	k = func(z) + func(y);
	printf_s("%d %d %d\n", z, y, k);
	k = funclink(z) + funclink(y);
	printf_s("%d %d %d\n", z, y, k);
	system("pause");
	return 0;
}