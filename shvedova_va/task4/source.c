#include <stdio.h>
#include <string.h>
#define arr_size 45
int main()
{
	char* product[arr_size] = { "���� ����� 400��.", "���� �������� 400��.", "���� ��������� 100��.", "���� �������� 35��.", "����� 300��.","��� 250��.",
		"������ 2,5% 1�.", "����� 3,2% 1�.", "������� 4% 350��.", "������ 9% 400�.", "������� 20% 180�.", "��� ������ 50% 150�.",
		"��� ������� 45% 150�.", "��� ���������� 50% 150�.", "��� ��������� 140�.", "��� ���������� 200�.", "������� ������������� 250�.", "������� ���������� 500�.",
		"���� ������� 1��.", "���� �� ������� 1��.", "���� ������� 1��.", "������ �������������� 1��.", "����� ����������� 240�.", "������ ��������� 1��.",
		"����� 1 ��.", "������ 1��.", "�������� ��������", "��������� 1��.", "������ ��������� 1��.", "������ 1��.",
		"����� ������� 1��.", "����� �������� 330�.", "���� ������� �������� 250�.", "������� ������� 500�.", "������� ������� 500�.", "����� � ������",
		"����� � ��������", "�������� � ��������", "������� ������ � ��������", "������� ������ 55%", "������� ��������", "������� � ���������",
		"��� �������� 1�.", "��� �������� 1�.", "��� ����������� 1�." };
	char* barcode[arr_size] = { "1201", "1202", "1203", "1204", "1205", "1206", "1401", "1402", "1403", "1404", "1405", "1901", "1902", "1903", "1904", "1905",
		"1601", "1602", "2201", "2202", "2203", "1001", "2001", "3301", "3302", "3303", "3304", "3305", "1601", "1602", "1603", "2301", "2302", "1701", "1702",
		"1703", "1704", "1705", "2601", "2602", "2603", "2604", "0301", "0302", "0303" };
	int price_for_one[arr_size] = { 150, 150, 90, 50, 60, 40, 72, 80, 49, 149, 65, 135, 136, 150, 137, 184, 220, 249, 450, 419, 389, 249, 159, 87, 129, 74, 109,
		119, 139, 80, 119, 48, 43, 189, 170, 76, 40, 50, 125, 100, 78, 90, 149, 139, 129 };
	int count_in_check[arr_size]={0}, discount[arr_size]={0};
	int flag, summa = 0, number = 0, count_of_products = 0;
	float price, all_discount, summa_with_discount = 0;
	char barcode_scan[5], add[4];
	system("chcp 1251");
	system("cls");
	//������� �������
	printf("������� ������� � �������: \n");
	for (int i = 0; i < arr_size; i++)
		printf("%d) %s - ���.: %s \n", i + 1, product[i], barcode[i]);
	//������� ������ � ����������� �� ��������� �� ������� ������
	for (int i = 0; i < arr_size; i++)
	{
		if (price_for_one[i] <= 50)
			discount[i] = 5;
		else
			if ((price_for_one[i] > 50) && (price_for_one[i] <= 80))
				discount[i] = 10;
			else
				if ((price_for_one[i] > 80) && (price_for_one[i] < 100))
					discount[i] = 15;
				else
					if ((price_for_one[i] >= 100) && (price_for_one[i] < 130))
						discount[i] = 20;
					else
						if ((price_for_one[i] >= 130) && (price_for_one[i] < 150))
							discount[i] = 25;
						else
							if ((price_for_one[i] >= 150) && (price_for_one[i] <= 170))
								discount[i] = 30;
							else
								if ((price_for_one[i] > 170) && (price_for_one[i] <= 200))
									discount[i] = 35;
								else
									if ((price_for_one[i] > 200) && (price_for_one[i] < 350))
										discount[i] = 40;
									else
										if ((price_for_one[i] >= 350) && (price_for_one[i] < 450))
											discount[i] = 45;
										else
											discount[i] = 50;
	}
	//������������ �����-����
	while (1)
	{
		printf("\n������� �����-��� ������ �� �������� (��� ������� 0, ����� ������������ ���): ");
		scanf_s("%s", barcode_scan, (int)sizeof barcode_scan);
		flag = 0;
		if (strcmp("0", barcode_scan) != 0)
		{
			for (int i = 0; i < arr_size; i++)
			{
				if (strcmp(barcode[i], barcode_scan) == 0)
				{
					system("cls");
					printf("%s - %d ���.\n���-�� � ���� �� ������ ������: %d\n�������� ����� � ���? (��/���): ", product[i], price_for_one[i], count_in_check[i]);
					scanf_s("%s", add, (int)sizeof add);
					if (strcmp("��", add) == 0)
					{
						count_in_check[i]++;
						count_of_products++;
						summa += price_for_one[i];
						system("cls");
						printf("����� ������� ��������\n����� (��� ����� ������): %d ���.", summa);
					}
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				printf("������ �������� �����-���\n");
		}
		else
			break;
	}
	system("cls");
	//������������ ����
	if (count_of_products != 0)
	{
		printf("\t�������� ���:\n");
		for (int i = 0; i < arr_size; i++)
		{
			if (count_in_check[i] != 0)
			{
				number++;
				price = (price_for_one[i] - (price_for_one[i] * discount[i] / 100)) * count_in_check[i];
				summa_with_discount += price;
				printf("%d) %s\n%dx%d ���.\n� ������ ������ %d ���������: %.2f ���.\n", number, product[i], count_in_check[i], price_for_one[i], discount[i], price);
			}
		}
		all_discount = summa - summa_with_discount;
		printf("\n����� ����� ������: %.2f ���.\n", all_discount);
		printf("�����: %.2f ���.\n", summa_with_discount);
	}
	else
		printf("� ����� ���� ��� �������...\n");
	system("pause");
	return 0;
}