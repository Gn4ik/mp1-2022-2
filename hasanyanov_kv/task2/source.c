#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int kpop = 0, i, n, win = 0, mode; // i - ���������� �����, n - �������������, mode - ����� ����, kpop - ���������� �������.
	printf("������� ����� ����:\n1 - �� ���������� �����\n2 - ��������� ��������� �����\n");
	scanf_s("%d", &mode);
	if (mode == 1)
	{
		srand(time(NULL)); // ��� �������� �������� ����� �����������.
		i = (rand() % 1000) + 1; 
		printf("���� �������, ������� �������� '1001'\n");
		printf("�������� ����� (�� 1 �� 1000)\n");
		while (win != 1)
		{
			kpop++;
			scanf_s("%d", &n); // ���� ��� ������� ���������, �� ���� ��������� ������ ���������.
			if (n == 1001)
				printf("%d\n", i);
			else if (n > i)
				printf("����������� ����� ������\n");
			else if (n < i)
				printf("���������� ����� ������\n");
			else if (n == i) {
				printf("�������!!!");
				win = 1;
			}
		}
		printf("�� ��������, ����� �������:" "%d", kpop);
		system("PAUSE");
	}
	else if (mode == 2)
	{
		char znak;
		int min = 0, max = 1000; // ����� ����� ������� ������������� ������������ �������� ��������, ���� �� ������� ������ �����.
		printf("��������� ����� �� 1 �� 1000, � � �������� ��� ��������\n");
		srand(time(NULL)); // ��� �������� �������� ����� �����������.
		scanf_s("%c", &znak);
		while (win != 1)
		{
			i = rand() % ((max - min) + 1) + min;
			printf("%d?\n", i);
			scanf_s(" %c", &znak);
			if (znak == '>')
			{
				kpop++;
				min = i;
			}
			else if (znak == '<')
			{
				kpop++;
				max = i;
			}
			else if (znak == '=')
			{
				kpop++;
				win = 1;
			}
			else
			{
				printf("�������� ������!\n");
				system("PAUSE");
			}
		}
		printf("� �������!!! ���������� �������:" "%d\n", kpop);
		system("PAUSE");
	}
	return 0;
}
