#include <math.h>
#include <stdio.h>
#include <locale.h>


void main()
{
	setlocale(LC_ALL, "Rus");
	float x1, y1, r1, x2, y2, r2;
	float dist;

	printf("������� x � y ������ ����������, � ����� � ������: ");
	scanf("%f %f %f", &x1, &y1, &r1);	
	printf("������� x � y ������ ����������, � ����� � ������: ");
	scanf("%f %f %f", &x2, &y2, &r2);

	dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2)); //������� pow - ���������� � �������

	if ((r1 = r2) && (y1 = y2) && (x1 = x2)) // && - and
	{
	printf("���������� ���������, ���� ����� �� ������");
	}
	 else if (dist > (r1 + r2))
	{
		printf("���������� ��������");
	}
	else if (dist < abs(r1 - r2))
	{
		printf("���� ���������� ��������� � ������");
	}
	else if (dist = abs(r1 - r2))
	{
		printf("���� ���������� ��������� � ������ � ��� ����, ��� ����� ����� �����");
	}
	else if (abs(r1 - r2) < dist < (r1 + r2))
	{
		printf("���������� ������������, ����� ��� ����� �����");
	}
	else if (dist = (r1 + r2))
	{
		printf("���������� �������������");
	}
}
