#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "RUS");
	int m[10][4] = {
		{1,1,1,1},
		{1,2,3,4},
		{1,2,4,3},
		{4,3,2,1},
		{1,4,5,6},
		{4,8,3,5},
		{7,9,4,1},
		{9,2,1,7},
		{3,9,1,1},
		{9,1,3,9}
	};
	const char* a[10];
	a[0] = "����(��)";
	a[1] = "���";
	a[2] = "����";
	a[3] = "����";
	a[4] = "����� ������������";
	a[5] = "C������";
	a[6] = "������";
	a[7] = "����";
	a[8] = "�������(��)";
	a[9] = "������(��)";
	int c[10] = { 350, 250, 40, 350,120,50,80,90,200,70};
	int b[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	float c1[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
	int skidka[10] = { 10, 15,5,25,10,5,15,20,5,5 };
	int count[10] = { 0, };
	int h,  n1, o, o1, choise,choise1,sum1;
	float obshst[10] = { 0, };
	float sum,skidk;
	do
	{
		n1 = 1;
		printf("������� ����� - ���\n");
		int i = 0;
		h = 100;
		while (i < 4)
		{
			scanf_s("%d", &b[i]);
			i++;
		}
		for (int k = 0; k < 10; k++) {
			/*printf("%c", name[i]);*/
			for (int j = 0; j < 10; j++)
			{
				if (m[k][j] != b[j])
					break;
				else
					if (j == 3)
					{
						h = k;
					}
			}
		}
		if (h == 100)
		{
			printf("����� �� ������\n");
			printf("1 - ������ ��� ���, 2 - �������\n");
			scanf_s("%d", &choise1);
			switch (choise1) {
			case 1:
				n1 = 0;
				break;
			case 2:
				break;
			}
		}
		else
		{
			printf("%s -  %d ���\n", a[h], c[h]);
			printf("������� 1, ���� ������ �������� ����� � ��� � ��a�������� ���������\n");
			printf("������� 2, ���� ������ ����������� ��������� �����, �� �� ��������� ������\n");
			printf("������� 3, ���� ������ ������������ ���\n");
			scanf_s("%d", &choise);
			switch (choise) {
			case 1:
				count[h]++;
				n1 = 0;
				break;
			case 2:
				n1 = 0;
				break;
			case 3:
				o = 0;
				sum = sum1 = 0;
				count[h]++;
				printf("        �������� ���\n");
				printf("�����    ���-��(��/��)    ���� �� �������(���)     ���� �� �������(���)    ����� ��������� �� �����\n");
				printf("---------------------------------------------------------------------------------------------------\n");
				while (o < 10)
				{
					if (count[o] > 0)
					{
						sum1 = sum1 + c[o] * count[o];
						c1[o] = c[o] - ((c[o] * 0.01) * skidka[o]);
						obshst[o] = c1[o] * count[o];
						printf("%-8s          %-8d              %-8d                %.2f                       %-8.2f\n", a[o], count[o], c[o], c1[o], obshst[o] );
						sum = sum + c1[o] * count[o];
						o++;
					}
					else
						o++;

				}
				skidk = sum1 - sum;
				printf("---------------------------------------------------------------------------------------------------\n");
				printf("   ��� ����� = %-2d ���.\n   ����� ������ = %.2f ���.\n   � ������ - %.2f ���.\n", sum1, skidk, sum);
				break;
			}
		}
	} while (n1 == 0);
	system("pause");
}

	




