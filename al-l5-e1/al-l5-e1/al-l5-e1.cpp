// al-l5-e1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


struct Adres
{
	char street[64];
	int num_H;
	int num_F;
};

struct Gitel
{
	char fio[128];
	Adres adr;
	char pol;
	int vozr;
};

int main()
{
	int n;
	printf_s("n = "); scanf_s("%d", &n);
	Gitel *pG = new Gitel[n];
	for (int i = 0; i < n; i++)
	{
		printf_s("Gitel N = %d", i + 1);
		printf_s("\nFIO: ");
		_flushall();
		scanf_s("%s", &pG[i].fio, 127);
		printf_s("Address: ");
		printf_s("\nStreet: ");
		fflush(stdin);
		scanf_s("%s", &pG[i].adr.street, 63);
		printf_s("House: ");
		scanf_s("%d", &pG[i].adr.num_H);
		printf_s("Flat: ");
		scanf_s("%d", &pG[i].adr.num_F);
		printf_s("pol: ");
		fflush(stdin);
		std::cin >> pG[i].pol;
		printf_s("Vozrast: ");
		scanf_s("%d", &pG[i].vozr);
	}
	for (int i = 0; i < n; i++)
		printf_s("\n%s %s %d %d %c %d",
			pG[i].fio, pG[i].adr.street,
			pG[i].adr.num_H, pG[i].adr.num_F,
			pG[i].pol, pG[i].vozr);
	printf_s("\n");
	delete[] pG;
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
