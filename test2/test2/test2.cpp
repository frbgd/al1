// test2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	Gitel G;
		printf_s("\nFIO: ");
		_flushall();
		scanf_s("%s", &G.fio, 127);
		printf_s("Address: ");
		printf_s("\nStreet: ");
		fflush(stdin);
		scanf_s("%s", &G.adr.street, 63);
		printf_s("House: ");
		scanf_s("%d", &G.adr.num_H);
		printf_s("Flat: ");
		scanf_s("%d", &G.adr.num_F);
		printf_s("pol: ");
		fflush(stdin);
		std::cin >> G.pol;
		printf_s("Vozrast: ");
		scanf_s("%d", &G.vozr);

		printf_s("\n%s %s %d %d %c %d",
			G.fio, G.adr.street,
			G.adr.num_H, G.adr.num_F,
			G.pol, G.vozr);
	printf_s("\n");
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
