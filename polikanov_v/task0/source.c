#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>

#include <stdio.h>;
#include <math.h>;


void main() {
	double x1, x2, y1, y2, r1, r2, distance;
	setlocale(LC_ALL, "Rus");

	printf("�������: r1 >= r2! ��� ��������\n");

	printf("������� x1, y1, r1\n");
	scanf("%lf %lf %lf", &x1, &y1, &r1);

	printf("������� x2, y2, r2\n");
	scanf("%lf %lf %lf", &x2, &y2, &r2);

    distance = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
	s
	if ((distance < r1 + r2 && distance > r1 - r2) && (distance != 0)) {
		printf("���������� ����� 2 ����� �����");
	}
	else if (r1 + r2 < distance) {
		printf("���������� �� ����� ����� �����, ���� �� ����� � ������");
	}
	else if ((x1 == x2 && y1 == y2) && r1 != r2) {
		printf("���������� ���������������, �� ����� ����� �����");
	}
	else if ((x1 == x2 && y1 == y2) && r1 == r2) {
		printf("���������� �������� ���� �� �����(����. ���-�� ��� �����)");
	}
	else if (distance < r1 - r2) {
		printf("���� ���������� ����� � ������, ����� ����� ���, ������ �� ���������");
	}
	else if (distance == r1 - r2) {
		printf("���������� �������� ������");
	}
	else if (distance == r1 + r2) {
		printf("���������� ����� 1 ����� �����");
	}

	scanf("%lf %lf %lf", &x2, &y2, &r2); // ��� ����, ����� ������� �� ��������� � ����� ���� ������� ���������


}
