#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

int main() {
	float x, y;

	printf("Vvedite x,y= ");
	scanf_s("%f%f", &x, &y);

	if ((y <= (x + 1)) && (y >= 0) && ((y*y) <= (-(x*x)-2*x)))
		printf("Tochka prinadlezhit oblasti");
	else
		printf("Tochka ne prinadlezhit oblasti");

	_getch();
}