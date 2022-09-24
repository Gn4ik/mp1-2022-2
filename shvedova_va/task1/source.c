#include <stdio.h>
#include <locale.h>
#include <math.h>
void main()
{
	double height, width, depth, thickness_inside, density_wood, M, m_back, m_side, m_bottom, m_inside,m_doors;
	int p; //��������� ���������� �����
	const double density_dsp = 700, density_dvp = 800, thickness_back = 0.005, thickness_side = 0.015, thickness_bottom = 0.015, thickness_door=0.01;
	setlocale(LC_ALL, "Russian");
	printf("������� ������ ����� � �������� 180-220 ��: ");
	scanf_s("%lf", &height);
	printf("������� ������ ����� � �������� 80-120 ��: ");
	scanf_s("%lf", &width);
	printf("������� ������� ����� � �������� 50-90 ��: ");
	scanf_s("%lf", &depth);
	printf("������� ��������� ������������� ������ � ��/�^3: ");
	scanf_s("%lf", &density_wood);
	printf("������� ������� ���������� ����� � �������� 5-15 ��: ");
	scanf_s("%lf", &thickness_inside);
	p = height / 40;
	height = height / 100; //������ � ������
	width = width / 100; //������ � ������
	depth = depth / 100; //������� � ������
	thickness_inside = thickness_inside / 1000; //������� ���������� ����� � ������
	m_back = thickness_back * height * width * density_dvp; //����� ������ ������
	m_side = thickness_side * height * depth * density_dsp; //����� ��������
	m_bottom = thickness_bottom * width * depth * density_dsp; //����� ������/������� ������
	m_inside = thickness_inside * depth * (width - 2 * thickness_side) * density_dsp; //����� ���������� �����
	m_doors = thickness_door * height * width * density_wood; //����� ������
	M = m_back + 2 * m_side + 2 * m_bottom + p * m_inside + m_doors;
	printf("����� ����� ����� = %lf", M);
	system("pause");
}