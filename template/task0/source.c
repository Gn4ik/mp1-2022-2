#include <stdio.h>
#include <iostream>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");

	double d, R, r, x, y, X, Y;
	printf("������� r, x, y\n");
	scanf_s("%lf %lf %lf", &r, &x, &y);
	printf("������� R, X, Y\n");
	scanf_s("%lf %lf %lf ", &R, &X, &Y);
	if (((X - x) * (X - x) + (Y - y) * (Y - y)) > R + r)
		printf("���������� �� ��������\n");
	else if (((X - x) * (X - x) + (Y - y) * (Y - y)) < R - r)
		printf("���� ���������� �������� � ������\n");
	else if (((X - x) * (X - x) + (Y - y) * (Y - y)) == R - r)
		printf("���� ���������� ������� ������ �������\n");
	else if (R - r < ((X - x) * (X - x) + (Y - y) * (Y - y)) < R + r)
		printf("���������� ������������\n");
	else if (((X - x) * (X - x) + (Y - y) * (Y - y)) == R + r)
		printf("���������� ��������\n");
	return 0;
}
