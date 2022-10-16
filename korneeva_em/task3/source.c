#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
void main()
{
	setlocale(LC_ALL, "Russian");
	int replay=1;
	while (replay != 0)
	{
		int num = 0, cnt1 = 0, cnt2, len, n, multiplier = 1, flag, try, bulls, cows, attempts = 0;
		// num - ���������� �����; cnt1,cnt2 - ��������; len - ����� �����
		// try - �������������� �����; bulls - ����; cows - ������; attempts - ������� �������
		// multiplier - ��������������� ��������� ��� �������� ���������� ����� ��� ����������
		int number[5]; // ������ ��� ������ ���� ����������� �����
		int guess[5]; // ������ ��� ������ ���� ��������������� ����� 
		printf("\n������� ����� ������������� ����� ����� �� 2 �� 5):");
		scanf_s("%d", &len);
		if ((len > 1) && (len < 6))
		{
			printf("���� �������� �������, ������� '0'");
			srand(time(NULL));
			int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //������ �� �������� ������� ��������� �����
			while (cnt1 != len)
			{
				cnt1 += 1;
				flag = 0;
				n = rand() % 10;
				while (flag != 1)
				{
					if (a[n] != 100)
					{
						num += a[n] * multiplier;
						number[cnt1 - 1] = a[n]; //������� ��� ������ ���� ����������� ����� � ������
						a[n] = 100; //������ ������� ������� ���������� �� 100, ��� ���� ����� ��� ����� �� ������� ��������
						flag = 1;
					}
					else n = rand() % 10; //���� �������������� ����� ��� ���� �����, ����� ���������� ��������� ������
				}
				if (cnt1 == len - 1)
					a[0] = 100; //��� �������� ��� ���� ����� ������� ����� �� ��������� ����
				multiplier = multiplier * 10;
			}
			flag = 0;
			while (flag != 1)
			{
				printf("\n������� ������������� �����:");
				scanf_s("%d", &try);
				attempts++;
				bulls = 0;
				cows = 0;
				if (try!=0)
				{
					for (cnt1 = 0; cnt1 < len; cnt1++) //���� ��� ������ ���� ��������������� ����� � ������ 
					{
						guess[cnt1] = try % 10;
						try /= 10;
					}
					for (cnt1 = 0; cnt1 < len; cnt1++) //��� ����� for ��������� ��������� ������������ ���� ���� ���� �����
					{
						for (cnt2 = 0; cnt2 < len; cnt2++)
						{
							if ((cnt1 == cnt2) && (number[cnt1] == guess[cnt2]))
								bulls++;
							else if ((cnt1 != cnt2) && (number[cnt1] == guess[cnt2]))
								cows++;
						}

					}
					if (bulls == len)
					{
						flag = 1;
						printf("\n�� �������! :)\n");
						printf("���������� ��������� �������: %i ", (attempts - 1));
					}
					else
						printf("���������� �����: %i, ���������� �����: %i\n ", bulls, cows);
				}
				else 
				{
					printf("���������� �����: %i ", num);
					printf("���������� ��������� �������: %i ", (attempts - 1));
					flag = 1;
				}
			}
			printf("\n\n������ �� �� ������� ��� ���?\n(������� '1' ���� ������� ����������, ���� �� ������ ��������� ���� ������� '0'): ");
			scanf_s("%d", &replay);
		}
		else printf("�������� ����� �����������\n");
	}
	getch();
}