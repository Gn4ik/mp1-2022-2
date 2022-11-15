#define _CRT_SECURE_NO_WARNINGS
#include <limits.h> 
#include <locale.h> 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> // ��������,��������� ���������� ������. ��� �������� ���������� <string.h> �-� strcmp ������-�� ��������
#include <string.h> 
#define COUNT_OF_PRODUCTS 7

char* products[COUNT_OF_PRODUCTS] = { "���� ������� �2 \"�����\" �������� 10�� ","������ \"� ������� ������ \" ����� 500��", "   ����� ���� \" ��� ������ \" 0.33�    ","        ����� \" � ���� � ����\"        ","   ������ \"������� � ������\" 300��    ","������� \"��, ��� ����\" �������� 350�� ","     ������ \"Love is programming\"     " };
char* codes[COUNT_OF_PRODUCTS] = { "0001","0002","0003","0004","0005","0006","0007"};
int prices[COUNT_OF_PRODUCTS] = { 90,70,65,40,110,150,35 };
int discounts[COUNT_OF_PRODUCTS] = { 0,0,0,0,0,0,0 }; // ������ ������. ����������� �������� � ������� time(NULL)
int numberInCheck[COUNT_OF_PRODUCTS] = { 0,0,0,0,0,0,0 }; // ���-�� ��������� ������� ����
int finallyCostThisProduct = 0; // ���� ����������� �������� � ������ ������
int allCost = 0; // ����� ���� ��� ����� ������
int finallyCostSumm = 0; // ����� ���� � ������ ������

int scan() {

	char code[100]; // ������ ����� 100 ��������. ���� �������� ������ ������� 100 ��������, ��������� ��������
	unsigned int isIn = 0; // ���� �� ��������� ��� � ������� �����
	unsigned int numberInProducts = 0; // ������ �������������� ���� �������� � ������ ���������

	printf("������� ������������� ��� ������:\n");
	scanf("%s", code);
	printf("\n");

	if (strcmp(code, "0") == 0) { // ���������� -1, ���� ����� 0
		return -1;
	}

	for (int i = 0; i < COUNT_OF_PRODUCTS; i++) { // ��������� ���������� ���� � ������������
		if (strcmp(code,codes[i]) == 0) {
			isIn = 1;
			numberInProducts = i;
		}
	}
	if (isIn == 1) {
		printf("| ����� %s | %s | ��������� %d ������ | ������ %d%% | \n\n", codes[numberInProducts], products[numberInProducts], prices[numberInProducts], discounts[numberInProducts]);
		return numberInProducts; // ���������� ������� ���������� �����-����(�����������)

	}
	else {
		printf("������ � ����� ����� ��� � �������\n");
		return -2; // ������� �������� -2 � ������ �� ���� ���� (�� ��������� �� 0!)
	}

}

void main(){
	int scanResult = 0;

	setlocale(LC_ALL, "Rus");

	printf("����� 21:59, ������ ������, �� ������ �� ������, ���� ������ - � ������ ������� ������� ���������� ����������\n������ ����� �����-���� ����� � ������, ������, ������ ������, �� ��������� ������, � ���� �� ��� �� � �����, � � ����\n\n����: 0001 - ���� 0002 - ������� 0003 - ���� 0004 - ���� 0005 - ������ 0006 - ������� 0007 - ������\n��� ���������� ������������ ������� 0\n");

	srand(time(NULL)); // ����� � �������� �� 1 ������ 1970�

	for (int i = 0; i < COUNT_OF_PRODUCTS; i++) { // ���������� ������ �������� ������ �������
		discounts[i] = abs(rand() % 10 + 1) * 5;
	}

	printf("\n");

	while (scanResult != -1) { // ���������� ��������� �����
		scanResult = scan();
		if (scanResult != -2 && scanResult != -1) {
			numberInCheck[scanResult]++; // ������ � ���-��� ������� � ���� (������)
		}
	}

	printf("|          ��� ���:          |\n");
		for (int i = 0; i < COUNT_OF_PRODUCTS; i++) {
			if (numberInCheck[i] != 0) {
				finallyCostThisProduct = round((prices[i] * (100 - discounts[i])) / 100 * numberInCheck[i]) / 1; // ���� ����������� �������� � ������ ������
				finallyCostSumm += finallyCostThisProduct; // ����� � ������(�� �������)
				allCost += prices[i] * numberInCheck[i]; // ����� ���������(��� ������)
				printf("| ����� %s | %s | ��������� �� ������� %d ������ | ���������� %d | ����� ��������� � ������ ������ = %d� |\n", codes[i], products[i],prices[i], numberInCheck[i], finallyCostThisProduct);
			}
		}
		printf("\n����� ��������� �������: %d�\n��������� ������: %d�\n����� � ������: %dp\n���? ����?\n", allCost,allCost-finallyCostSumm,finallyCostSumm);

	


	system("PAUSE");
}                 