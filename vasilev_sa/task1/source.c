#include <stdio.h>
#include <math.h>
#include <locale.h>

int Count_of_shelfs(float start_h, float t5);
int Count_of_shelfs(float start_h, float t5)
{
	float count = 0, all_height = 40;
	while ((all_height + t5) < start_h)
	{
		count += 1;
		all_height += (40 + t5);
	}
	return (int)count;
}

void main() 
{
	// �����������
	setlocale(LC_ALL, "Russian");
	// ���������� ����������
	int count;
	double h = 0, w = 0, d = 0;
	double value_1, value_2, value_3, value_4, value_5, all_value;
	const double t1 = 0.5, t2 = 1.5 , t3 = 1.5, t4 = 1, t5 = 1.5;
	const double material_DSP = 0.00075, material_DVP = 0.0004, material_wood = 0.00065;
	// ���� �������� � ����������� ��������
	printf("���������� ������ ��������� �������:\n(���� �������� ��� ���������, �� ��������� ��������� ������ ������)\n");
	while ((h < 180)||(h > 220))
	{
		printf("������� ������ �� 180 �� 220 (� ��): ");
		scanf_s("%lf", &h);
	}
	while ((w < 80)||(w > 120))
	{
		printf("������� ������ �� 80 �� 120 (� ��): ");
		scanf_s("%lf", &w);
	}
	while ((d < 50)||(d > 90))
	{
		printf("������� ������� �� 50 �� 90 (� ��): ");
		scanf_s("%lf", &d);
	}
	// ���������� �������
	count = Count_of_shelfs(h, t5);
	value_1 = (h * w * t1) * material_DVP;								// ������ ������ �� ���
	value_2 = 2 * (h * d * t2) * material_DSP;							// ������� ������ �� ���
	value_3 = 2 * (w * d * t3) * material_DSP;							// ������ �� ���
	value_4 = (h * w * t4) * material_wood;								// ����� �� ������
	value_5 = (w * d * t5) * count * material_DSP;						// ���������� ����� �� ���
	// ���� �����
	all_value = value_1 + value_2 + value_3 + value_4 + value_5;
	// ����� ������
	printf("\n�����:\n����� %d, ", count);
	printf("��� ����� %.2lf �� \n(��� ���������� ��� = 750 ��/��������, ��� = 400 ��/�������� � ������ = 650 ��/��������)\n\n", all_value);
	system("pause");
}