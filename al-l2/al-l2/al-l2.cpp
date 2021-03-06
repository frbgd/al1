// al-l2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

double Addition(double a, double b);
double Subtraction(double a, double b);
double Multiplication(double a, double b);
double Division(double a, double b);
double Exponentiation(double a, double b);
double SquareRootExtraction(double a);

int main()
{
	double a, b;
    std::cout << "Enter two numbers: ";
	std::cin >> a >> b;
	double c = Addition(a, b);
	double d = Subtraction(a, b);
	double e = Multiplication(a, b);
	double f = Division(a, b);
	double g = Exponentiation(a, b);
	double h = SquareRootExtraction(a);
	std::cout << "a + b = " << c << std::endl;
	std::cout << "a - b = " << d << std::endl;
	std::cout << "a * b = " << e << std::endl;
	std::cout << "a / b = " << f << std::endl;
	std::cout << "a ^ b = " << g << std::endl;
	std::cout << "sqrt(a) = " << h << std::endl;
	system("pause");
}

double Addition(double a, double b)
{
	double c = a + b;
	return c;
}

double Subtraction(double a, double b)
{
	double c = a - b;
	return c;
}

double Multiplication(double a, double b)
{
	double c = a * b;
	return c;
}

double Division(double a, double b)
{
	double c = a / b;
	return c;
}

double Exponentiation(double a, double b)
{
	int c = b;
	if (c == 0)
		return 1;
	double d = 1;
	if (c < 0)
	{
		c = -c;
		for (int i = 1; i <= c; i++)
			d *= a;
		d = 1 / d;
	}
	else
	{
		for (int i = 1; i <= c; i++)
			d *= a;
	}
	return d;
}

double SquareRootExtraction(double a)
{
	if (a <= 0)
		return 0;
	if (a == 1)
		return 1;
	double f = 0, res = a;
	while ((f - res > 0.00001) || (f - res < -0.00001))
	{
		f = res;
		res = (f + a / res) / 2;
	}
	return res;
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
