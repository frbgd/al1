// al-l7-e1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

struct BOOK
{
	char Author[64];
	char Title[128];
	char Firm[64];
	int year, page;
};

int main()
{
	int n;
	BOOK *pBook;
	printf_s("n="); scanf_s("%d", &n);
	pBook = new BOOK[n];
	for(int i = 0; i < n; i++)
	{
		printf_s("Book = %d:\n", i + 1);
		printf_s("Author: ");
		fflush(stdin); scanf_s("%s", &pBook[i].Author, 63);
		printf_s("Title: ");
		fflush(stdin); scanf_s("%s", &pBook[i].Title, 127);
		printf_s("Firm: ");
		fflush(stdin); scanf_s("%s", &pBook[i].Firm, 63);
		printf_s("year: "); scanf_s("%d", &pBook[i].year);
		printf_s("page: "); scanf_s("%d", &pBook[i].page);
	}
	FILE *pF;
	fopen_s(&pF, "MyBook.dat", "wb");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(pBook, sizeof(BOOK), n, pF);
	fclose(pF);
	delete[] pBook;
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
