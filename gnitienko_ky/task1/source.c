#include <stdio.h>
#include <math.h>
#include <locale.h>
void main() {
	setlocale(LC_ALL, "Rus");

	double  h = 0, w = 0, d = 0, l = 0.015, DVP = 800, DSP = 750, TREE = 650, v1 = 0, v2 = 0, v3 = 0, v4 = 0, v5 = 0; // v1 - ����� ������ �����, v2 - �������� �� ���,  
	// v3 - ������� ��� ������ ������, v4 - ��������� �����, v5 - �����
	double m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0, m_full = 0;
	int count_of_shelf;

	printf("������� ������ ����� h �� 180 �� 220 ��: ");
	scanf_s("%lf", &h);
	if (h < 180 || h > 220) {
		printf("������\n");
		return 1;
	}

	printf("������� ������ ����� w �� 80 �� 120 ��: ");
	scanf_s("%lf", &w);
	if (w < 80 || w > 120) {
		printf("������\n");
		return 1;
	}

	printf("������� ������� ����� d �� 50 �� 90 ��: ");
	scanf_s("%lf", &d);
	if (d < 50 || d > 90) {
		printf("������\n");
		return 1;
	}

	v1 = h * 0.01 * w * 0.01 * 0.0005;
	m1 = DVP * v1;
	printf("����� ������ ������ �� ���: %.2lf ��\n", m1);

	v2 = h * 0.01 * d * 0.01 * 0.0015;
	m2 = (DSP * v2) * 2;
	printf("����� ���� ������� �� ���: %.2lf ��\n", m2);

	v3 = w * 0.01 * d * 0.01 * 0.0015;
	m3 = (DSP * v3) * 2;
	printf("����� ���� ������ �� ���: %.2lf ��\n", m3);

	v4 = h * 0.01 * w * 0.01 * 0.01;
	m4 = (v4 * TREE) * 2;
	printf("����� ������ �� ������: %.2lf ��\n", m4);

	count_of_shelf = (h * 0.01) / (0.4 + l);
	v5 = d * 0.01 * w * 0.01 * l * DSP;
	printf("���-�� ����� = %i\n", count_of_shelf);
	m5 = count_of_shelf * v5;
	printf("����� ���� �����: %.2lf\n", m5);

	m_full = m1 + m2 + m3 + m4 + m5;

	printf("����� �����: %.2lf ��\n", m_full);
	system("pause");
	return 1;
}