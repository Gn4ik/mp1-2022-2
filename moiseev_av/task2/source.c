#include <math.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h> //���������� ��� ��������� ��������� �����//


void main()
{
	setlocale(LC_ALL, "Rus");

	int cnt, num, user_num, v1, v2, user_v;
	float answ, answ1, dist; //���������� ��� ��������� ��������� ������//
	char user_answ;
	printf("����� ���������� � ���� '������ �����'!\n\n");
	printf("� ����� ������� ���� �� �� ������ �������,\n� ������ ��� �� ������?\n� ������ ������ ��� ����� ����� ������� �����,\n� �� ������ - �������� �\n(������� ��������������� �����):\n"); //����� ������ ����//
	scanf_s("%d", &user_v);

	if (user_v == 1)
	{
		srand(time(0));
		num = 1 + rand() % 1000;
		printf("\n���������: %d\n\n", num);
		printf("� ������� ����� �� 1 �� 1000\n������� �����, � � ���� �������� - ������ ��� ������:\n");
		while (1)
		{
			scanf_s("%d", &user_num);
			if (user_num > num)
			{
				printf("���������� ����� ������!\n");
			}
			else if (user_num < num)
			{
				printf("���������� ����� ������!\n");
			}
			else
			{
				printf("�������!\n");
				break;
			}
		}
	}
	else if (user_v == 2)
	{
		printf("� �������������� ������ ���� ����� �����, ��� �� 15 �������!\n������� ���������� ���� ����� (�� 1 �� 1000)\n");
		scanf_s("%d", &user_num);
		if ((1 <= user_num) && (user_num < 1000)) //�������� ����������������� �����//
		{
			printf("��� ������ ������� �������� �������: '<', '>', '=' \n");
			answ1 = 1000;
			dist = 0;
			answ = 500;
			cnt = 0;
			while (1) //����� ������������ �������� ��������� ������, ��� ����� �������� ������ �����//
			{

				printf("���� �����: %f?\n", answ);
				scanf_s(" %c", &user_answ);
				if (user_answ == '>')
				{
					dist = abs(answ1 - answ);
					answ1 = answ;
					if (answ >= 994)
					{
						answ = answ + 1;
					}
					answ = answ + (int)(dist / 2);
					cnt++;
				}
				else if (user_answ == '<')
				{
					dist = abs(answ1 - answ);
					answ1 = answ;
					if (answ <= 6)
					{
						answ = answ - 1;
					}
					else if ((int)(dist) % 2 == 0)
					{
						answ = answ - (int)(dist / 2);
					}
					else
					{
						answ = (int)(answ - (dist / 2)) + 1;
					}
					cnt++;
				}
				else if (user_answ == '=')
				{
					printf("���!\n���� �����: %f\n���������� �������: %d\n", answ, cnt);
					break;
				}
				else
				{
					printf("��� ������ ������� �������� ������� : '<', '>', '=' \n");
				}
			}
		}
		else
		{
			printf("������� ����� �� 1 �� 1000!\n");
		}
	}
	else
	{
		printf("������ ������!\n������� 1 ��� 2\n");
	}
}
