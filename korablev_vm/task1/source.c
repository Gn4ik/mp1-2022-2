#include <stdio.h>
#include <locale.h>
#include <math.h>//������� 
int shelves_count(float h)//������� �������� ���������� �����
{
	float sh_count = 0, ThicknessUsed = 40;
	while ((ThicknessUsed+1.5)<=h)
	{
		sh_count = sh_count + 1; 
		ThicknessUsed = ThicknessUsed + 41.5; 
	}
	return (int)sh_count;
}
void main()
{
	setlocale(LC_ALL, "Rus");//�����������
	//������� ���������� � �������� 
	float h = 0, w = 0, d = 0,m; //���������� ������� �����
	float dsp, dvp, wood;//��������� ����������
	float t_dsp = 1.5, t_dvp = 0.5, t_door = 1; //������� ����������
	int sh;//���������� �����
	//
	//��������� ���������� + �������� ������ 
	while ((h < 180) || (h > 220))
	{
		printf("������� ������ (�� 180 �� 220 ��) ������ ������ ");
		scanf("%f", &h);
	}
	while ((w < 80) || (w > 120))
	{
		printf("������� ������ (�� 80 �� 120 ��) ������ ������ ");
		scanf("%f", &w);
	}
	while ((d < 50) || (d > 90))
	{
		printf("������� ������� (�� 50 �� 90 ��) ����� ");
		scanf("%f", &d);
	}
	printf("���������! �������� ��������� ����������: ��� = 400 ��/� ��� = 750 ��/� ������ = 650 ��/� \n");
	printf("������� ��������� ���, ��� � ������ � ��/�������� ");
	scanf("%f %f %f", &dvp, &dsp, &wood);
	sh = shelves_count(h);
	//
	//�������������� ��������
	dvp = dvp / 1000000; //���������� ���������� � ��/���������� ���������
	dsp = dsp / 1000000;
	wood = wood / 1000000;
	m = (h * w * t_dvp * dvp) + (2 * h * d * t_dsp * dsp) + (2 * w * d * t_dsp * dsp) + (h * w * t_door * wood) + (sh * w * d * t_dsp * dsp);
	printf("����� ����� ����� %f �� \n", m);
	system("pause");
	//
}