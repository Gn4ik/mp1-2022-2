#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int kpop = 0, i, predict, win = 0, mode; // i - ���������� �����, predict - �������������, mode - ����� ����, kpop - ���������� �������.
	printf("������� ����� ����:\n1 - �� ���������� �����\n2 - ��������� ��������� �����\n");
	scanf_s("%d", &mode);
	if (mode == 1)
	{
		srand(time(NULL)); // ��� �������� �������� ����� �����������.
		i = (rand() % 1000) + 1; 
		printf("���� �������, ������� �������� '1001'\n"); // ���� ��� ������� ���������, �� ���� ��������� ������ ���������.
		printf("�������� ����� (�� 1 �� 1000)\n");
		while (win != 1)
		{
			kpop++;
			scanf_s("%d", &predict);
			if (predict == 1001)
				printf("%d\n", i);
			else if (predict > i)
				printf("����������� ����� ������\n");
			else if (predict < i)
				printf("���������� ����� ������\n");
			else if (predict == i)
			{
				printf("�������!!!\n");
				win = 1;
			}
		}
		printf("�� ��������, ����� �������:" "%d\n", kpop);
		system("PAUSE");
	}
	else if (mode == 2)
	{
		char znak;
		int min = 0, max = 1000, random; // ����� ����� ������� ������������� ������������ �������� ��������, ���� �� ������� ������ �����.
		printf("��������� ����� �� 1 �� 1000, � � �������� ��� ��������\n");
		system("PAUSE");
		srand(time(NULL)); // ��� �������� �������� ����� �����������, ������� ����� ��������� �����.
		scanf_s("%c", &znak);
		while (win != 1)
		{
			random = rand() % (max - min + 1) + min; //������� � ������ ����������� ������ � �����.
			printf("��� ����� ""%d?\n", random);
			scanf_s(" %c", &znak);
			switch (znak)
			{
				case '>': 
				{
					kpop++;
					min = random + 1;
					break;
				}
				case '<':
				{
					kpop++;
					max = random - 1;
					break;
				}
				case '=':
				{
					kpop++;
					win = 1;
					break;
				}
				default:
				{
					printf("�������� ������!\n");
					system("PAUSE");
				}
			}
		}
		printf("� �������!!!\n ���������� �������:" "%d\n", kpop);
		system("PAUSE");
	}
	else
	{
		printf("�������� ������\n");
		system("PAUSE");
	} 
	return 0;
}