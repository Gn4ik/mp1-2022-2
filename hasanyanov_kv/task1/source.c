#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	double   tolshina1, tolshina2, tolshina3, tolshina4, tolshina5, Value1, Value2, Value3, Value4, Value5, Massa, Plotnost1, Plotnost2, Plotnost3;
	// R - ��������� ���������
	int k5, h, w, d;
	tolshina1 = 0.5;
	tolshina2 = 1.5;
	tolshina3 = 1.5;
	tolshina4 = 1;
	tolshina5 = 1.5;
	// ������ ��������� ��������� ����������
	Plotnost3 = 540;
	Plotnost2 = 800;
	Plotnost1 = 700;
	// 1 - ���, 2 - ���, 3 - ������
	// V - ������ ��������������� �������, k - ���������� ����� � ����������� �� ������
	printf("������� ������� ������ ������ � ��. (������, ������)\n");
	if (scanf_s("%d %d", &h, &w) != 2 || h > 220 || h < 180 || w > 120 || w < 80)
	{
		printf("�������� ������\n");
		return 1;
	}
	printf("������� ������� ����� � ��.\n");
	if (scanf_s("%d", &d) != 1 || d > 90 || d < 50)
	{
		printf("�������� ������\n");
		return 1;
	}
	// �������� ���������� �����
	if (h % 40 == 0)
		k5 = h / 40 - 1;
	else
		k5 = h / 40;
	// �������� ������ ������� � ����������� �� �� ���-�� � ��������
	Value1 = h * w * tolshina1;
	Value2 = 2 * h * d * tolshina2;
	Value3 = 2 * w * d * tolshina3;
	Value4 = 2 * h * w * tolshina4;
	Value5 = k5 * tolshina5 * w * d;
	Massa = (Plotnost1 * Value1 + Plotnost2 * (Value2 + Value3 + Value5) + Plotnost3 * Value4) * 0.000001;
	printf("����� ����� ����� %lf ��", Massa);
	system("PAUSE");
	return 0;
}