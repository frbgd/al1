// al-l7-t1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

struct AUTO
{
	char Model[64];
	int* fuelcons[3];
	int maxs, power;
};

int main()
{
	int n;
	AUTO *pAuto;
	printf_s("n="); scanf_s("%d", &n);
	pAuto = new AUTO[n];
	for (int i = 0; i < n; i++)
	{
		printf_s("Auto = %d:\n", i + 1);
		printf_s("Model: ");
		fflush(stdin); scanf_s("%s", &pAuto[i].Model, 63);
		printf_s("Fuel consumption:\n");
		printf_s("on the road: ");  scanf_s("%d", &pAuto[i].fuelcons[0]);
		printf_s("in the city: ");  scanf_s("%d", &pAuto[i].fuelcons[1]);
		printf_s("mixed: ");  scanf_s("%d", &pAuto[i].fuelcons[2]);
		printf_s("maxs: "); scanf_s("%d", &pAuto[i].maxs);
		printf_s("power: "); scanf_s("%d", &pAuto[i].power);
	}
	FILE *pF;
	fopen_s(&pF, "MyAuto.txt", "wt");
	//здесь надо записать в файл текст
	fprintf(pF, "%d\n", n);
	for(int i=0; i < n; i ++)
		fprintf(pF, "%s %d %d %d %d %d\n", pAuto[i].Model, pAuto[i].fuelcons[0], pAuto[i].fuelcons[1], pAuto[i].fuelcons[2],
		pAuto[i].maxs, pAuto[i].power);
	fclose(pF);
	delete[] pAuto;
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
