#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
void main()
{
	setlocale(LC_ALL, "Russian");
	int n, flag, cnt, mode, max, min, try;
	char sign;
	// mode - ����� ����, n - ���������� �����, try - ������� �������, cnt - ������� �������
	// ���������� max � min ����������� ��� ���������� ����� �� ������ ������
	printf("�������� ����� ����: \n (1 - ����� ������������ ����������, 2 - ����� ���������� ������������) \n");
	scanf_s("%d", &mode);
	cnt = 0;

	if (mode==1)
	{
		srand(time(NULL));
		n = 1 + rand() % 1001;
		while (1)
		{
			cnt += 1;
			printf("������� ��������: ");
			scanf_s("%d", &try);
			if (try < n)
				printf("���������� ����� ������ \n");
			else if (try > n)
				printf("���������� ����� ������ \n");
			else if (try == n)
			{
				printf("�������\n");
				printf("���������� �������:");
				printf("%d", cnt);
				break;
			}
		}
	}
	else if (mode==2)
	{
		printf("������� ���������� �����: \n");
		scanf_s("%d", &n);
		max = 1001;
		min = 1;
		flag = 0;
		while (1)
		{
			cnt += 1;
			try = round((max - min) / 2) + min;
			printf("���������� ����� %i?\n", try);
			printf("������� ������ ���������� ����� ������, ������ ��� �����: \n");
			scanf_s("\n%c", &sign);
			if (sign == '<')
				max = try;
			if (sign =='>')
				min = try;
			if (sign == '=')
			{
				printf("�������\n");
				printf("���������� �������:");
				printf("%d", cnt);
				break;
			}
			
		}
	}
	

	getch();
}