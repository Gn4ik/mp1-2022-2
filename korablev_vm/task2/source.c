#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>//�������
void main()
{
	setlocale(LC_ALL, "Rus");//�����������
	int mode=0, rn, SelectedNumber=0, AttemptsCount=0,c=500,mn=0,mx=1001,c1;
	char sn,enter;
	while ((mode < 1) || (mode>2))
	{
		printf("�������� ����� ���� (1 - ���������� ��, 2 - ��������� ���������) = ");
		scanf_s("%d", &mode);
	}
	if (mode==1)//������ �����
	{
		srand(time(NULL));
		rn = (rand() % 1000)+1;
		printf("����� ��������. �������� �������������, ��������� �������� ��� �� ������ ���� ");
		while (SelectedNumber != rn)
		{
			scanf_s("%d", &SelectedNumber);
			AttemptsCount++;
			if (SelectedNumber > rn)
			{
				printf("���������� ����� ������. ��������� ������� - ");
			}
			else if (SelectedNumber < rn)
			{
				printf("���������� ����� ������. ��������� ������� - ");
			}
		}
		printf("�����������! �� �������! ���������� ����� - %d. ���������� ������� - %d \n", rn,AttemptsCount);
	}
	if (mode == 2)//������ �����
	{
		printf("�� �������� �����. ��� ������ ��� ������ 500? \n");
		printf("(���������: ���� ����� ������, ������� ���� >, ������ - ���� <. ���� ����� �������, ������� =) ");
		scanf_s("%c", &enter);
		scanf_s("%c", &sn);
		AttemptsCount = 1;
		while (sn != '=')
		{
			c1 = c;
			if (sn == '>') 
			{
				mn = c;
				c = (mn + ((mx-mn) / 2));
			}
			else if (sn == '<')
			{
				mx = c;
				c = (mn + ((mx - mn) / 2));
			}
			if (c1 == c)
				break;
			if (c == 0) {
				printf("�� ������ �������� \n");
				system("pause");
				_Exit(EXIT_SUCCESS);
			}
			AttemptsCount++;
			printf("���� ����� ������ ��� ������, ��� %d? ", c);
			scanf_s("%c", &enter);
			scanf_s("%c", &sn);
		}
		printf("���������� ����� = %d. ���������� ������� = %d. \n", c, AttemptsCount);
	}
	system("pause");
}