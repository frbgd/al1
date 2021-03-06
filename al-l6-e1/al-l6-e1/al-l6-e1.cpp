// al-l6-e1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


struct Sotr
{
	char fio[64];
	char date[16];
	char dolg[32];
	int okl;
};

struct List
{
	Sotr sotr;
	List *pNext;
};

void addFirst(List *& pF, List* p)
{
	p->pNext = pF;
	pF = p;
}

List * delFirst(List *&pF)
{
	if (pF == 0)
		return 0;
	List *p = pF;
	pF = pF->pNext;
	return p;
}

bool add(List *&pF, List * pZad, List *p)
{
	if (pZad == pF)
	{
		p->pNext = pF;
		pF = p;
		return true;
	}
	List *pPred = pF;
	while (pPred->pNext != pZad && pPred->pNext)
		pPred = pPred->pNext;
	if (pPred->pNext == 0) return false;
	p->pNext = pZad;
	pPred->pNext = p;
	return true;
}

List * del(List*& pF, List *p)
{
	if (pF == 0) return 0;
	if (pF == p)
	{
		pF = pF->pNext;
		return p;
	}
	else
	{
		List *pPred = pF;
		while (pPred->pNext != p && pPred->pNext)
			pPred = pPred->pNext;
		if (pPred->pNext == 0)
			return 0;
		pPred->pNext = p->pNext;
		return p;
	}
	while (delFirst(pF));
}

int main(int argc, char* argv[])
{
	List *pF = 0;
	List *p;
	char Ch;
	do
	{
		p = (List *)malloc(sizeof(List));
		printf_s("\nFIO: ");
		fflush(stdin); scanf_s("%s", &p->sotr.fio, 63);
		printf_s("Date: ");
		fflush(stdin); scanf_s("%s", &p->sotr.date, 15);
		printf_s("Dolg: ");
		fflush(stdin); scanf_s("%s", &p->sotr.dolg, 31);
		printf_s("Okl: ");
		fflush(stdin); scanf_s("%d", &p->sotr.okl);
		addFirst(pF, p);
		printf_s("For continue print Y or y, else any key! ");
		std::cin >> Ch;
	} while (Ch == 'Y' || Ch == 'y');
	
	for (List *pi = pF; pi; pi = pi->pNext)
		printf_s("\n%s %s %s oklad=%d", pi->sotr.fio, pi->sotr.date, pi->sotr.dolg, pi->sotr.okl);

	for (List *pi = pF; pi->pNext;)
	{
		double min = pi->sotr.okl;
		List *pmin = pi;
		for(List *pj = pi->pNext; pj; pj = pj->pNext)
			if (pj->sotr.okl < min)
			{
				min = pj->sotr.okl;
				pmin = pj;
			}
		if (pi != pmin)
		{
			del(pF, pmin);
			add(pF, pi, pmin);
		}
		else pi = pi->pNext;
	}
	printf_s("\nString:");
	for (List *pi = pF; pi; pi = pi->pNext)
		printf_s("\n%s %s %s oklad=%d", pi->sotr.fio, pi->sotr.date, pi->sotr.dolg, pi->sotr.okl);
	printf_s("\n");
	system("pause");
	free(p);
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
