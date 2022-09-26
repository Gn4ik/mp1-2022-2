#include <stdio.h>
#include <math.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
void main()
{
	setlocale(LC_ALL, "Russian");
	double h, w, d, p_DSP, p_DVP, p_wood, t1, t2, t3, x, m_side_walls, m_back_wall, m_doors, m_covers, m_shelfs,m;
	int shelfs_cnt;
	p_DSP = 600; //��������� ���
	p_DVP = 750; //��������� ���
	p_wood = 700; //��������� ������
	shelfs_cnt = 0; //���������� ����� � �����
	t1 = 0.005; //������� ���
	t2 = 0.015; //������� ���
	t3 = 0.01; //������� ������
	printf("������� � ����������� ��������� ����� ����� ������ (������, ������ � �������):");
	scanf_s("%lf %lf %lf", &w, &h, &d);
	if ((w >= 80) && (w <= 120) && (h >= 180) && (h <= 220) && (d >= 50) && (d <= 90))
	{
		x = h; //��������������� ���������� ��� �������� ���������� ����� � �����
		while (x > 40)
		{
			shelfs_cnt += 1;
			x -= 40;
		}
		m_side_walls = (h * 0.01 * d * 0.01 * t2) * p_DSP * 2;
		m_back_wall = (h * 0.01 * w * 0.01 * t1) * p_DVP;
		m_covers = (w * 0.01 * d * 0.01 * t2) * p_DSP * 2;
		m_doors = (h * 0.01 * w * 0.01 * t3) * p_wood;
		m_shelfs = (w * 0.01 * d * 0.01 * t2) * p_DSP * shelfs_cnt;
		m = m_side_walls + m_back_wall + m_covers + m_doors + m_shelfs;
		printf("m = %lf", m);
	}
	else printf("������ �����������");
	getch();
}