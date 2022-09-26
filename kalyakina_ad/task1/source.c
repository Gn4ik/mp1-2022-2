#include <stdio.h>
#include <math.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Rus");
	float h, d, w;
	float m;
	float Pdsp, Pdvp, Ptree;
	int count;
	printf("������ ���������������: ������, ������ � ������� �����(� �����������) ");
	scanf_s("%f %f %f", &h, &w, &d);
	if ((h < 180) || (h > 220)) printf("����������� ������� ������ ����� ");
	else if ((w < 80) || (w > 120)) printf("����������� ������� ������ ����� ");
	else if ((d < 50) || (d > 90)) printf("����������� ������� ������� ����� ");
	else
	{
		count = 0;
		while (h > 40)
		{
			h = h - 40;
			count++;
		}
		h = h + count * 40;
		printf("������ ��������������� ��������� ���, ��� � ������(� �^3/��) ");
		scanf_s("%f %f %f", &Pdsp, &Pdvp, &Ptree);
		if (Pdsp <= 0) printf("����������� ������� ��������� ��� ");
		else if (Pdvp <= 0) printf("����������� ������� ��������� ��� ");
		else if (Ptree <= 0) printf("����������� ������� ��������� ������ ");
		else
		{
			m = (Pdvp * h * w * 0.5 + Pdsp * 2 * d * 1.5 * (w + h) + Ptree * h * w + Pdsp * 1.5 * (w - 3) * d * count) / 1000000;
			printf("����� ����� = %f ", m);
		}
	}
	system("pause");
}