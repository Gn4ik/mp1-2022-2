#include <stdio.h>
#include <math.h>
#include<locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	double h, w, d, backwall_weight, sidewall_weight, topNbottom_weight, doors_weight, shelves_weight, total_weight; // backwall - ��������� ������ ������, sidewall - ��������, topNbottom - ��������� ������� � ������ ������, doors - ��������� ����� �� ������, shelves - �����
	int shelves_count;
	const double backwall_thickness = 0.5, sidewall_thickness = 1.5, topNbottom_thickness = 1.5, door_thickness = 1, DVPdensity = 0.00078, DSPdensity = 0.00066, WOODdensity = 0.00052; // density in kg/cm^3, thickness in cm
	const int shelf_interval = 40; // distance in cm
	printf("������� �������� h, w, d � �����������\n");
	scanf_s("%lf%lf%lf", &h, &w, &d);

	if ((h >= 180) & (h <= 220) & (w >= 80) & (w <= 120) & (d >= 50) & (d <= 90))
	{
		backwall_weight = ((h * w * backwall_thickness) * DVPdensity);
		sidewall_weight = (2 * ((h * d * sidewall_thickness) * DSPdensity));
		topNbottom_weight = (2 * ((w * d * topNbottom_thickness) * DSPdensity));
		doors_weight = (2 * ((h * w * door_thickness) * WOODdensity));
		shelves_count = (h / (shelf_interval + sidewall_thickness));
		shelves_weight = (((w * d * topNbottom_thickness) * DSPdensity) * shelves_count);
		total_weight = (backwall_weight + sidewall_weight + topNbottom_weight + doors_weight + shelves_weight);
		printf("���� ����� %lf �����������\n", total_weight);
		printf("���������� ����� � ����� - %d\n", shelves_count);
	}
	else
	{
		printf("�������� �������� �����������. ���������� �����\n");
	}
	system("PAUSE");
		
}