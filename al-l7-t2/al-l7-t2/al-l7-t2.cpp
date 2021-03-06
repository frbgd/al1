// al-l7-t2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

struct AUTO
{
	char Model[64];
	int* fuelcons[3];
	int maxs, power;
};

struct List
{
	AUTO data;
	List *pNext;
};

int main()
{
	int n;
	List *pAuto = 0;
	List *p;
	FILE *pF;
	fopen_s(&pF, "MyAuto.txt", "rt");
	if (pF == 0)
	{
		printf_s("Error, file not found\n");
		system("pause");
		return 1;
	}
	fscanf_s(pF, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		p = (List *)malloc(sizeof(List));
		fscanf_s(pF, "%s", &p->data.Model, 63);
		fscanf_s(pF, "%d %d %d %d %d", &p->data.fuelcons[0], &p->data.fuelcons[1], &p->data.fuelcons[2], &p->data.maxs,
			&p->data.power);
		p->pNext = pAuto;
		pAuto = p;
	}
	fclose(pF);
	int j = 0;
	for (List *pi = pAuto; pi; pi = pi->pNext)
	{
		j++;
		printf_s("\nAuto %d:\n", j);
		printf_s("Model: %s\n", pi->data.Model);
		printf_s("Fuel consumption:\n");
		printf_s("On the road = %d\n", pi->data.fuelcons[0]);
		printf_s("In the city = %d\n", pi->data.fuelcons[1]);
		printf_s("Mixed = %d\n", pi->data.fuelcons[2]);
		printf_s("Max speed = %d\n", pi->data.maxs);
		printf_s("Power = %d\n", pi->data.power);
	}
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
