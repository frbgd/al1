// al-ekz-3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
	float h, m;
	float xn;
	float i = 0;
	do
	{
		printf_s("h="); scanf_s("%f", &h);
		printf_s("m="); scanf_s("%f", &m);
	} while ((m <= h) || (m >= 4));
	do
	{
		i++;
		xn = (2 * i - 1) * 2 / i;
		//printf_s("%d  %f\n", i, xn);
	} while (xn < h);
	int nmin = i;
	printf_s("%d  %f\n", nmin, xn);
	while (xn <= m)
	{
		i++;
		xn = (2 * i - 1) * 2 / i;
		//printf_s("%d  %f\n", i, xn);
	}
	int nmax = i;
	printf_s("%d  %f\n", nmax, xn);
	int count = nmax - nmin;
	printf_s("%d\n", count);
	system("pause");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
