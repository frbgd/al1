// al-l5-t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

unsigned Evklid(int a, int b)
{
	while (a != 0 && b != 0)
	{
		if (a == b)
			return a;
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

int main(int argc, char *argv[])
{
	int a, b, nod;
	setlocale(LC_ALL, "rus");
	if (argc < 3)
	{
		printf_s("Ошибка: параметров в командной строке не хватает для задания исходных данных.\n");
		system("pause");
		return 1;
	}
	sscanf_s(argv[1], "%d", &a);
	if (a < 1)
	{
		printf_s("Ошибка: неверный формат первого входного параметра.\n");
		system("pause");
		return 1;
	}
	sscanf_s(argv[2], "%d", &b);
	if (b < 1)
	{
		printf_s("Ошибка: неверный формат первого входного параметра.\n");
		system("pause");
		return 1;
	}
	nod = Evklid(a, b);
	printf_s("a = %d, b = %d, nod = %d. Сокращенная дробь: %d/%d.\n", a, b, nod, a / nod, b / nod);
	system("pause");
	return 0;
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
