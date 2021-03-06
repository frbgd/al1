// typescplusplus.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// data_types.cpp: определяет точку входа для консольного приложения.
#include <iostream>
// библиотека манипулирования вводом/выводом
#include <iomanip>
// заголовочный файл математических функций
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
	cout << "     data type      " << "byte" << "      " << "    max value  " << endl // заголовки столбцов
		<< "bool               =  " << sizeof(bool) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных bool*/ << (pow(2, sizeof(bool) * 8.0) - 1) << endl
		<< "char               =  " << sizeof(char) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных char*/ << (pow(2, sizeof(char) * 8.0) - 1) << endl
		<< "short int          =  " << sizeof(short int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных short int*/ << (pow(2, sizeof(short int) * 8.0 - 1) - 1) << endl
		<< "unsigned short int =  " << sizeof(unsigned short int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных unsigned short int*/ << (pow(2, sizeof(unsigned short int) * 8.0) - 1) << endl
		<< "int                =  " << sizeof(int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных int*/ << (pow(2, sizeof(int) * 8.0 - 1) - 1) << endl
		<< "unsigned int       =  " << sizeof(unsigned int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных unsigned int*/ << (pow(2, sizeof(unsigned int) * 8.0) - 1) << endl
		<< "long int           =  " << sizeof(long int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных long int*/ << (pow(2, sizeof(long int) * 8.0 - 1) - 1) << endl
		<< "unsigned long int  =  " << sizeof(unsigned long int) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных undigned long int*/ << (pow(2, sizeof(unsigned long int) * 8.0) - 1) << endl
		<< "float              =  " << sizeof(float) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных float*/ << (pow(2, sizeof(float) * 8.0 - 1) - 1) << endl
		<< "long float         =  " << sizeof(long float) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных float*/ << (pow(2, sizeof(long float) * 8.0 - 1) - 1) << endl
		<< "double             =  " << sizeof(double) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных double*/ << (pow(2, sizeof(double) * 8.0 - 1) - 1) << endl
		<< "long double        =  " << sizeof(long double) << "         " << fixed << setprecision(2)
		/*вычисляем максимальное значение для типа данных double*/ << (pow(2, sizeof(long double) * 8.0 - 1) - 1) << endl;
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
