#include <stdio.h>
#include <math.h>
void main()
{
	double R1, R2, x1, y1, x2, y2, d;
	printf("������� R1");
	scanf_s("%lf", &R1);
	printf("������� ���������� x1 � y1");
	scanf_s("%lf %lf", &x1, &y1);
	printf("������� R2");
	scanf_s("%lf", &R2);
	printf("������� ���������� x2 � y2");
	scanf_s("%lf %lf", &x2, &y2);
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); //���������� ����� �������� �����������
	if ((R1 < R2 + d) && (R2 < R1 + d) && (d < R1 + R2))
		printf("���������� ������������");
	if (abs(R1 - R2) == d)
		printf("���������� �������� ���������� �������");
	if (R1 + R2 == d)
		printf("���������� �������� ������� �������");
	if (R1 + R2 < d)
		printf("���������� ����� ��� ���� �����");
	if ((R1 + d < R2) || (R2 + d < R1))
		printf("���������� ����������� ���� ������ ������");
	if ((R1 == R2) && (x1 == x2) && (y1 == y2))
		printf("���������� �������� ���� �� �����");
	system("pause");
}

